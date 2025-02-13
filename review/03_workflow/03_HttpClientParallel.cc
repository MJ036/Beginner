#include "mai.h"
#include <cstdio>
#include <workflow/HttpMessage.h>
#include <workflow/WFFacilities.h>
#include <workflow/WFHttpServer.h>
#include <workflow/WFTask.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/HttpUtil.h>
#include <workflow/Workflow.h>
using namespace std;
using namespace protocol;

struct SeriesContext{
    string url;
    int state;
    int error;
    HttpResponse resp;
};



using WFHttpTask = WFNetworkTask<protocol::HttpRequest,
                                protocol::HttpResponse>;


//并行任务的回调函数
void callback(const ParallelWork *pwork){
    SeriesContext *ctx;
    const void *body;
    size_t size;
    size_t i;
    for(i = 0; i < pwork->size();i++){
        ctx = (SeriesContext*)pwork->series_at(i)->get_context();
        printf("%s\n",ctx->url.c_str());
        if(ctx->state == WFT_STATE_SUCCESS){
            ctx->resp.get_parsed_body(&body,&size);
            printf("%zu%s\n", size, ctx->resp.is_chunked() ? " chunked" : "");
            fwrite(body,1,size,stdout);
            printf("\n");
        }else{
            printf("ERROR! state = %d, error = %d\n", ctx->state, ctx->error);
        }
        delete ctx;
    }
    
}


int main(int argc, char* argv[])
{
    ParallelWork *pwork = Workflow::create_parallel_work(callback);
    SeriesWork *series;
    WFHttpTask *task;
    HttpRequest *req;
    SeriesContext *ctx;
    vector<string> urlVector = {"http://www.baidu.com",
    "http://10.211.55.4:1280","192.168.6.1"};
    for(int i = 0; i < urlVector.size(); ++i){
        string url = urlVector[i];
        task = WFTaskFactory::create_http_task(url,0,0,[](WFHttpTask *task){
                                               SeriesContext *ctx = (SeriesContext*)series_of(task)->get_context();
                                               ctx->state = task->get_state();
                                               ctx->error = task->get_error();
                                               ctx->resp =std::move(*task->get_resp());
                                               });
        req = task->get_req();
        req->add_header_pair("Accept","*/*");
        req->add_header_pair("User-Agent","Wget/1.14(linux-gnu)");
        req->add_header_pair("Connection","close");
        ctx = new SeriesContext;
        ctx->url = std::move(url);
        series = Workflow::create_series_work(task,nullptr);
        series->set_context(ctx);
        pwork->add_series(series);
    }
    WFFacilities::WaitGroup wait_group(1);
    Workflow::start_series_work(pwork,[&wait_group](const SeriesWork*){
                                wait_group.done();
                                });
    wait_group.wait();

    return 0;
}

