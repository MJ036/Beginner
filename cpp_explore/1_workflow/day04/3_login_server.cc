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
    string password;
    //process阶段就把resp指针存起来，方便后续使用
    protocol::HttpResponse *resp;
};
static WFFacilities::WaitGroup gWaitGroup(1); 
// 阻塞主线程，直到按下ctrl+c
void handler(int signum){
    printf("signum = %d\n", signum);
    gWaitGroup.done(); //计数器减一
}
void redisCallback(WFRedisTask *redisTask){
    cout << "redisCallback is called\n";
    protocol::RedisResponse *resp = redisTask->get_resp();
    protocol::RedisValue value;
    resp->get_result(value);

    SeriesContext *context = (SeriesContext *)series_of(redisTask)->get_context();
    if(value.string_value() == context->password){
        context->resp->append_output_body("LOGIN SUCCESS");
    }
    else{
        context->resp->append_output_body("LOGIN FAILED");
    }
    delete context;
}
void serverTaskCallback(WFHttpTask * serverTask){
    cout << "serverTaskCallback is called\n";
}


void process(WFHttpTask * serverTask){
    cout << "process is called!\n";
    protocol::HttpRequest *req = serverTask->get_req();
    string uri = req->get_request_uri();
    cout << "uri = " << uri << "\n";

    string nameKV = uri.substr(0,uri.find("&"));
    string passwordKV = uri.substr(uri.find("&")+1);
    cout << "nameKV = " << nameKV << "\n";
    string name =  nameKV.substr(nameKV.find("=")+1);
    cout << "name = " << name << "\n";
    string password = passwordKV.substr(passwordKV.find("=")+1);
    cout << "password = " << password << "\n";

    SeriesContext * context = new SeriesContext;
    context->password = password;
    context->resp = serverTask->get_resp();
    series_of(serverTask)->set_context(context);

    WFRedisTask *redisTask = 
        WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",0,redisCallback);
    redisTask->get_req()->set_request("HGET",{"54user",name});
    series_of(serverTask)->push_back(redisTask);
    serverTask->set_callback(serverTaskCallback);
    cout << "process is returned\n";
}
int main(){
    signal(SIGINT,handler);
    WFHttpServer server(process);
    server.start(1234);
    gWaitGroup.wait();
    server.stop();
}
