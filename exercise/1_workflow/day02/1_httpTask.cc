#include <mai.h>
#include <iostream>
#include <workflow/WFFacilities.h>
#include <workflow/HttpMessage.h>
#include <workflow/HttpUtil.h>
using std::cout;

static WFFacilities::WaitGroup gWaitGroup(2);

void handler(int signum){
    printf("signum = %d\n",signum);
    gWaitGroup.done();
}

int main()
{
    signal(SIGINT,handler);

    cout << "1\n";
    WFHttpTask * httpTask = WFTaskFactory::create_http_task("http://192.168.96.131:1234",10,0,nullptr);
    cout << "2\n";
    protocol::HttpRequest *req = httpTask->get_req();
    req->add_header_pair("Accept","*/*");
    
    httpTask->start();
    cout << "3\n";

    gWaitGroup.wait();
    return 0;
}

