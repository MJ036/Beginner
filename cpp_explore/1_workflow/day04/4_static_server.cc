#include <mai.h>
#include <iostream>
#include <vector>
#include <string>
#include <workflow/WFFacilities.h>
#include <workflow/HttpMessage.h>
#include <workflow/HttpUtil.h>
#include <workflow/WFHttpServer.h>
using std::cout;
using std::string;
struct SeriesContext{
    protocol::HttpResponse *resp;
    char buf[4096];
};
static WFFacilities::WaitGroup gWaitGroup(1); 
// 阻塞主线程，直到按下ctrl+c
void handler(int signum){
    printf("signum = %d\n", signum);
    gWaitGroup.done(); //计数器减一
}

//IO任务回调函数
void fileIOCallback(WFFileIOTask *preadTask){
    cout << "fileIO callback/n";
    SeriesContext * context = (SeriesContext *)series_of(preadTask)->get_context();
    cout << "buf = " << context->buf << "\n";
    context->resp->append_output_body_nocopy(context->buf);
}

void process(WFHttpTask * serverTask){
    cout << "process is called! \n";
    protocol::HttpResponse *resp = serverTask->get_resp();
    resp->set_http_version("HTTP/1.1");
    resp->set_status_code("200");
    resp->set_reason_phrase("OK");
    resp->set_header_pair("Content-type","text/html");

    protocol::HttpRequest *req = serverTask->get_req();
    string method = req->get_method();
    if(method == "GET"){
        int fd = open("postform.html",O_RDONLY);
        SeriesContext * context = new SeriesContext;
        context->resp = resp;
        series_of(serverTask)->set_context(context);
        WFFileIOTask *preadTask = WFTaskFactory::create_pread_task(fd,context->buf,4096,0,fileIOCallback);
        series_of(serverTask)->push_back(preadTask);
    }
    else{
        resp->append_output_body("<html>YES</html>");
    }
}

int main(){
    signal(SIGINT,handler);
    WFHttpServer server(process);
    server.start(1234);
    gWaitGroup.wait();
    server.stop();
}
