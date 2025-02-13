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
#include <workflow/WFFuture.h>
#include <workflow/WFTask.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/RedisMessage.h>
#include <workflow/Workflow.h>
#include <workflow/WFServer.h>
#include <workflow/WFHttpServer.h>
#include <workflow/HttpUtil.h>
using namespace std;

struct SeriesContext{
    string url;
    //传递给newTask，使其可以修改响应
    WFHttpTask *serverTask;
};

static WFFacilities::WaitGroup waitGroup(1);

void sigHandler(int num){
    waitGroup.done();
    cout << "waitGroup is done\n";
}

void serverTaskCallback(WFHttpTask *httpTask){
   struct timeval tv;
   gettimeofday(&tv,NULL);
   fprintf(stderr,"serverTaskCallback start %ld.%06ld\n", tv.tv_sec,tv.tv_usec);
   SeriesWork *series = series_of(httpTask);
   SeriesContext *context = (SeriesContext*)series->get_context();
   auto resp = httpTask->get_resp();
   size_t size = resp->get_output_body_size();
   if(httpTask->get_state() == WFT_STATE_SUCCESS){
       cerr << "Http success" << endl;
   }
   gettimeofday(&tv,NULL);
   fprintf(stderr,"serverTaskCallback end %ld.%06ld\n", tv.tv_sec,tv.tv_usec);


}

void newTaskCallback(WFHttpTask *newTask){
    struct timeval tv;
    gettimeofday(&tv,NULL);
    fprintf(stderr,"newTaskCallback start %ld.%06ld\n", tv.tv_sec,tv.tv_usec);

    auto *resp = newTask->get_resp();
    int state = newTask->get_state();
    int error = newTask->get_error();
    auto *context = (SeriesContext*)series_of(newTask)->get_context();
    switch(state){
    case WFT_STATE_SYS_ERROR:
        fprintf(stderr,"system error:%s\n",strerror(error));
        break;
    case WFT_STATE_DNS_ERROR:
        fprintf(stderr,"DNS error:%s\n",strerror(error));
        break;
    case WFT_STATE_SSL_ERROR:
        cerr <<"SSL error :" << error << endl;
    case WFT_STATE_TASK_ERROR:
        cerr <<"Task error :" << error << endl;
    case WFT_STATE_SUCCESS:
        break;
    }
    if(state !=WFT_STATE_SUCCESS){
        fprintf(stderr,"Failed. Press Ctrl-C to exit.\n");
        return;
    }

    const void* body;
    size_t size;
    resp->get_parsed_body(&body,&size);
    resp->append_output_body_nocopy(body,size);
    auto serverTaskResp = context->serverTask->get_resp();
    *serverTaskResp = std::move(*resp);

    gettimeofday(&tv,NULL);
    fprintf(stderr,"newTaskCallback end %ld.%06ld\n", tv.tv_sec,tv.tv_usec);

}

void process(WFHttpTask *serverTask){
    struct timeval tv;
    gettimeofday(&tv,NULL);
    fprintf(stderr,"process start %ld.%06ld\n", tv.tv_sec,tv.tv_usec);

    //设置服务器任务的回调
    serverTask->set_callback(serverTaskCallback);

    protocol::HttpRequest *req = serverTask->get_req();
    protocol::HttpResponse *resp = serverTask->get_resp();

    SeriesWork *series = series_of(serverTask);
    SeriesContext *context = new SeriesContext;
    context->serverTask = serverTask;
    context->url = "http://10.211.55.4";
    series->set_context((void*)context);

    //设置序列的回调
    series->set_callback([](const SeriesWork *series){
                         struct timeval tv;
                         gettimeofday(&tv,NULL);
                         fprintf(stderr,"seriesCallback %ld.%06ld\n",tv.tv_sec,tv.tv_usec);
                         delete ((SeriesContext*)series->get_context());
                         });

    //新建一个http任务，并加入序列
    WFHttpTask *newTask = WFTaskFactory::create_http_task("http://10.211.55.4",5,2,newTaskCallback);
    series->push_back(newTask);
    gettimeofday(&tv,NULL);
    fprintf(stderr,"process end%ld.%06ld\n",tv.tv_sec,tv.tv_usec);





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

