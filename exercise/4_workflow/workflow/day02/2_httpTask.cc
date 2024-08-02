#include "mai.h"
#include <workflow/WFFacilities.h>
#include <workflow/HttpMessage.h>
#include <workflow/HttpUtil.h>

using namespace std;

static WFFacilities::WaitGroup gWaitGroup(2);

void handler(int signum){
    printf("signum = %d\n",signum);
    gWaitGroup.done();
}

void httpCallback(WFHttpTask *httpTask){
    cout << "4\n";
    protocol::HttpRequest *req = httpTask->get_req();
    protocol::HttpResponse *resp = httpTask->get_resp();

    //状态检查
    int state = httpTask->get_state();
    int error = httpTask->get_error();
    switch(state){
    case WFT_STATE_SYS_ERROR:
        cout << "system error:" << strerror(error) << "\n";
        break;
    case WFT_STATE_DNS_ERROR:
        cout << "dns error: " << gai_strerror(error) << "\n";
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
    while(cursorReq.next(key,value)){
        cout << "response key = " << key << ", value =" << value << "\n";
    }

    const void *body;
    size_t size;
    resp->get_parsed_body(&body,&size);
    cout << string((char *)body,size) << "\n";

}

int main()
{
    signal(SIGINT,handler);
    cout << " 1\n";

    WFHttpTask *httpTask = WFTaskFactory::create_http_task(
                        "http://172.19.79.160:1234",10,0,httpCallback);
                        //"http://www.baidu.com",10,0,httpCallback);
    cout << "2\n";

    protocol::HttpRequest *req = httpTask->get_req();
    req->add_header_pair("Accept","*/*");

    httpTask->start();
    cout << "3\n";
    gWaitGroup.wait();
}

