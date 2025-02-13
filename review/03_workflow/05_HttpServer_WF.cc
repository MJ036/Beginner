#include "mai.h"
#include <bits/types/struct_timeval.h>
#include <csignal>
#include <cstddef>
#include <cstdio>
#include <hiredis/read.h>
#include <netinet/in.h>
#include <sstream>
#include <sys/select.h>
#include <sys/socket.h>
#include <workflow/HttpMessage.h>
#include <workflow/WFFacilities.h>
#include <workflow/WFTask.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/RedisMessage.h>
#include <workflow/Workflow.h>
#include <workflow/WFServer.h>
#include <workflow/WFHttpServer.h>
#include <workflow/HttpUtil.h>
using namespace std;

static WFFacilities::WaitGroup waitGroup(1);

void sigHandler(int num){
    waitGroup.done();
}

void process(WFHttpTask *httpTask){
   struct timeval tv;
   gettimeofday(&tv,NULL);
   fprintf(stderr,"process start %ld.%06ld\n", tv.tv_sec,tv.tv_usec);

   protocol::HttpRequest *req = httpTask->get_req();
   protocol::HttpResponse *resp = httpTask->get_resp();
   resp->set_http_version("HTTP/1.1");
   resp->set_status_code("200");
   resp->set_reason_phrase("OK");
   resp->set_header_pair("Content-Type","text/plain");

   std::stringstream ss;
   ss << req->get_method() << " "
       << req->get_request_uri () << " "
       << req->get_http_version() << "\r\n";
   protocol::HttpHeaderCursor reqCursor(req);
   string name,value;
   while(reqCursor.next(name,value)){
       ss << name << " : " << value << "\r\n";
   }
   
   char addrstr[128];
   struct sockaddr_in addr;
   socklen_t len = sizeof(addr);
   unsigned short port;
   httpTask->get_peer_addr((sockaddr *)&addr,&len);
   if(addr.sin_family == AF_INET){
       ss << "sin_family:AF_INET" << "\r\n";
       ss << "ip:" << inet_ntoa(addr.sin_addr) <<"\r\n";
       ss << "port:" << ntohs(addr.sin_port) << "\r\n";
   }
   resp->append_output_body(ss.str());

   gettimeofday(&tv,NULL);
   fprintf(stderr,"process end %ld.%06ld\n",tv.tv_sec,tv.tv_usec);
   
}
int main()
{
    signal(SIGINT,sigHandler);

    struct WFServerParams params = HTTP_SERVER_PARAMS_DEFAULT;
    params.request_size_limit = 8*1024*1024;
    WFHttpServer server(&params,process);
    if(server.start(1234) == 0){
        waitGroup.wait();
        server.stop();
    }else{
        perror("server start failed!");
        exit(1);
    }
    return 0;
}

