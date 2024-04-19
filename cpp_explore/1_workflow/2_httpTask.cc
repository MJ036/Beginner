#include <mai.h>
#include <iostream>
#include <workflow/WFFacilities.h>
#include <workflow/HttpMessage.h>
#include <workflow/HttpUtil.h>
#include <string>

using std::cout;
using std::string;
static WFFacilities::WaitGroup gWaitGroup(2);
//阻塞主进程，知道按下ctrl+c
void handler(int signum){
    printf("signum = %d\n",signum);
    gWaitGroup.done();
}

void httpCallback(WFHttpTask *httpTask){
    cout << "4\n";

    protocol::HttpRequest *req = httpTask->get_req();
    protocol::HttpResponse *resp = httpTask->get_resp();
    int state = httpTask->get_state();
    int error = httpTask->get_error();
    switch(state){
    case WFT_STATE_SYS_ERROR:
        cout << "system error:" << strerror(error) << "\n";
        break;
    case WFT_STATE_DNS_ERROR:
        cout << "dns error:" << gai_strerror(error) << "\n";
        break;
    case WFT_STATE_SUCCESS:
        break;
    }
    if(state == WFT_STATE_SUCCESS){
        cout << "SUCCESS\n";
    }
    else{
        cout << "FAILED\n";
        return;
    }

    protocol::HttpHeaderCursor cursorReq(req);
    string key;
    string value;
    while(cursorReq.next(key,value)){
        cout << "request key = " << key << ", value = " << value << "\n";
    }
    protocol::HttpHeaderCursor cursorResp(resp);
    while(cursorResp.next(key,value)){
        cout << "response key = " << key << ", value = " << value << "\n";
    }

    const void *body;
    size_t size;
    resp->get_parsed_body(&body,&size);
    cout << string((char *)body,size) << "\n";

}

int main()
{
    signal(SIGINT,handler);

    cout << "1\n";
    //利用工厂函数创建一个任务
    //http://192.168.96.131:1234
    WFHttpTask * httpTask = WFTaskFactory::create_http_task("http://192.168.96.131:1234",10,0,httpCallback);
    //设置httpTask的属性：请求
    cout << "2\n";
    protocol::HttpRequest *req = httpTask->get_req();
    req->add_header_pair("Accept","*/*");
    //将任务派给框架，由框架异步调用
    httpTask->start();
    sleep(1);
    cout << "3\n";

    gWaitGroup.wait();
}

