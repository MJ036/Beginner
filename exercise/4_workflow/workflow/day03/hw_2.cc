#include "mai.h"
#include <workflow/WFFacilities.h>
#include <workflow/HttpMessage.h>
#include <workflow/HttpUtil.h>

using namespace std;

static WFFacilities::WaitGroup gWaitGroup(1);

void handler(int signum){
    printf("signum = %d\n",signum);
    gWaitGroup.done();
}

class HomeWork{
public:
    void init_query(){
        WFHttpTask *httpTask = 
            WFTaskFactory::create_http_task("http://www.taobao.com",10,0,
                                            std::bind(&HomeWork::on_http_response,this,std::placeholders::_1));
        httpTask->start();
    }

    void on_http_response(WFHttpTask *httpTask){
        protocol::HttpResponse *resp = httpTask->get_resp();
        const void *body;
        size_t size;
        resp->get_parsed_body(&body,&size);
        string value((char *)body,size);
        WFRedisTask *redisTask =
        WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",0,
                                         std::bind(&HomeWork::on_redis_return,this,std::placeholders::_1));
        redisTask->get_req()->set_request("SET",{"www.taobao.com",value});
        series_of(httpTask)->push_back(redisTask);
    }

    void on_redis_return(WFRedisTask *redisTask){
        protocol::RedisResponse *resp = redisTask->get_resp();
        protocol::RedisValue value;
        resp->get_result(value);
        if(value.is_ok()){
            cout << "value is " << value.string_value() << "\n";
        }

    }
};


int main()
{
    signal(SIGINT,handler);
    HomeWork homework;
    homework.init_query();
    gWaitGroup.wait();
}

