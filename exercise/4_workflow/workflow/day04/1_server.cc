#include "mai.h"
#include <workflow/WFFacilities.h>
#include <workflow/HttpMessage.h>
#include <workflow/HttpUtil.h>
#include <workflow/WFHttpServer.h>

using namespace std;

static WFFacilities::WaitGroup gWaitGroup(1);
// 阻塞主线程，直到按下ctrl+c
void handler(int signum){
    printf("signum = %d\n", signum);
    gWaitGroup.done(); //计数器减一
}

void process(WFHttpTask *serverTask){
    cout << "process is called!\n";
    protocol::HttpResponse * resp = serverTask->get_resp();
    resp->set_http_version("HTTP/1.1");
    resp->set_status_code("200");
    resp->set_reason_phrase("OK");
    resp->set_header_pair("Content-type","text/html");
    resp->append_output_body("<html>hello</html>");
}


int main(){
    signal(SIGINT,handler);
    WFHttpServer server(process);
    server.start(1234); // listen 1234 端口
    gWaitGroup.wait(); // 等待直到计数器为0
    server.stop();
}

