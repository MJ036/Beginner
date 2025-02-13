#include "mai.h"
#include <bits/types/struct_timeval.h>
#include <csignal>
#include <cstddef>
#include <cstdio>
#include <fcntl.h>
#include <hiredis/read.h>
#include <iostream>
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
    protocol::HttpRequest *req = httpTask->get_req();
    protocol::HttpResponse *resp = httpTask->get_resp();

    string method = req->get_method();
    cerr << method << endl;
    if(method == "GET"){
        int fd = open("postform.html",O_RDONLY);
        if(fd < 0){
            cerr << "open" << endl;
            resp->set_status_code("500");
            return;
        }
        char* buf = new char[4096];
        int size = read(fd,buf,4096);
        resp->append_output_body(buf,size);
    }
    else if(method == "POST"){
        const void *body;
        size_t len;
        req->get_parsed_body(&body,&len);
        std::cerr << "body is " << std::endl << (char *)body << std::endl;
        string wholeBody = (char*)body;
        size_t div = wholeBody.find("&");
        string username = wholeBody.substr(0,div);
        string password = wholeBody.substr(div+1);
        string usernameValue = username.substr(username.find("=")+1);
        string passwordValue = password.substr(password.find("=")+1);
        cerr << "usernameValue = " << usernameValue << endl;
        cerr << "passwordValue = " << passwordValue << endl;
        if(usernameValue == "admin" && passwordValue == "123"){
            resp->append_output_body("SUCCESS");
            resp->set_header_pair("Content-type","text/plain");
        }
        else{
            resp->append_output_body("FAIL");
            resp->set_header_pair("Content-type","text/plain");
        }
    }
}
int main()
{
    unsigned short port = 1234;
    signal(SIGINT,sigHandler);

    WFHttpServer server(process);
    if(server.start(port) == 0){
        waitGroup.wait();
        server.stop();
    }else{
        perror("server start failed!");
        exit(1);
    }
    return 0;
}

