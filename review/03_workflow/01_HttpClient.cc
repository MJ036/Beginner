#include "mai.h"
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstring>
#include <dirent.h>
#include <workflow/HttpMessage.h>
#include <workflow/WFFacilities.h>
#include<workflow/WFHttpServer.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/HttpUtil.h>
using namespace std;

static WFFacilities::WaitGroup wait_group(1);

void sig_handler(int signo){
    wait_group.done();
}

using WFHttpTask = WFNetworkTask<protocol::HttpRequest,
                                protocol::HttpResponse>;

void callback_getState(WFHttpTask *httpTask){
    int state = httpTask->get_state();
    int error = httpTask->get_error();
    switch(state){
    case WFT_STATE_SYS_ERROR:
        fprintf(stderr,"system error:%s\n",strerror(error));
        break;
    case WFT_STATE_DNS_ERROR:
        fprintf(stderr,"DNS error:%s\n",strerror(error));
        break;
    case WFT_STATE_SUCCESS:
        break;
    }
    if(state !=WFT_STATE_SUCCESS){
        fprintf(stderr,"Failed. Press Ctrl-C to exit.\n");
        return;
    }
    fprintf(stderr,"success\n");
    wait_group.done();
}

void callback_getContent(WFHttpTask *task){
    protocol::HttpRequest *req = task->get_req();
    protocol::HttpResponse *resp = task->get_resp();
    fprintf(stderr,
            "%s %s %s\r\n"
            , req->get_method(),
            req->get_http_version(),
            req->get_request_uri());
    fprintf(stderr,
            "%s %s %s\r\n"
            , resp->get_http_version(),
            resp->get_status_code(),
            resp->get_reason_phrase());
}

void callback_getHeader(WFHttpTask *task){
    protocol::HttpRequest *req = task->get_req();
    protocol::HttpResponse *resp = task->get_resp();

    string name,value;
    //遍历请求报文的首部字段
    protocol::HttpHeaderCursor req_cursor(req);
    while(req_cursor.next(name,value)){
        fprintf(stderr,"%s:%s\r\n",name.c_str(),value.c_str());
    }
    fprintf(stderr,"\r\n");
    //遍历响应报文的首部字段
    protocol::HttpHeaderCursor resp_cursor(resp);
    while(resp_cursor.next(name,value)){
        fprintf(stderr,"%s:%s\r\n",name.c_str(),value.c_str());
    }
    fprintf(stderr,"\r\n");
}

void callback_getBody(WFHttpTask *task){
    const void *body;
    size_t body_len;
    protocol::HttpResponse *resp = task->get_resp();
    resp->get_parsed_body(&body,&body_len);
    fwrite(body,1,body_len,stdout);
    fflush(stdout);
}



int main(int argc, char* argv[])
{
    // a.out url
    ARGS_CHECK(argc,2)
    signal(SIGINT,sig_handler);

    string url = "http://";
    url.append(argv[1]);
    //创建http任务对象
    auto httpTask = WFTaskFactory::create_http_task(url,0,0,callback_getBody);
    //设置http任务属性
    protocol::HttpRequest *req = httpTask->get_req();
    req->add_header_pair("Accept","*/*");
    req->add_header_pair("User-Agent","TestAgent");
    req->add_header_pair("connection","close");
    httpTask->start();
    wait_group.wait();
    return 0;
}

