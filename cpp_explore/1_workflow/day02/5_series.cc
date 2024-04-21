#include <mai.h>
#include <iostream>
#include <workflow/WFFacilities.h>
#include <workflow/HttpMessage.h>
#include <workflow/HttpUtil.h>
#include <string>
using std::cout;
using std::string;
struct SeriesContext{
    int i;
    string str;
};
static WFFacilities::WaitGroup gWaitGroup(1);
//阻塞主进程，知道按下ctrl+c
void handler(int signum){
    printf("signum = %d\n",signum);
    gWaitGroup.done();
}

int main()
{
    signal(SIGINT,handler);
    WFRedisTask *redisTask1 = WFTaskFactory::create_redis_task(
       "redis://127.0.0.1:6379",0,
       [](WFRedisTask *redisTask){
       protocol::RedisResponse *resp = redisTask->get_resp();
       //用来获取redis返回的结果
       protocol::RedisValue value;
       resp->get_result(value);
       SeriesContext * pcontext = new SeriesContext;
       series_of(redisTask)->set_context(pcontext);
       pcontext->i = 123;
       pcontext->str = "hello";
       if(value.is_string() && value.string_value() == "OK"){
       cout << "Task2 is created!\n";
       WFRedisTask *redisTask2 = WFTaskFactory::create_redis_task(
                     "redis://127.0.0.1:6379",0,
                     [](WFRedisTask *redisTask){
                        protocol::RedisResponse *resp = redisTask->get_resp();
                        protocol::RedisValue value;
                        resp->get_result(value);
                        SeriesContext *pcontext = (SeriesContext *)(series_of(redisTask)->get_context());
                        if(value.is_string()){
                            cout << "value = " << value.string_value() << "\n";
                            cout << "i = " << pcontext->i << " str = " << pcontext->str << "\n";
                        }
                     }
                    );
                    protocol::RedisRequest *req2 = redisTask2->get_req();
                    req2->set_request("GET",{"54"});
                    series_of(redisTask)->push_back(redisTask2);
       }else{
           cout << "Task2 is not created!\n";
       }
       series_of(redisTask)->set_callback(
                                          [](const SeriesWork *series){
                                          cout << "series callback\n";
                                          SeriesContext *pcontext = (SeriesContext *)(series->get_context());
                                          delete pcontext;
                                          }
                                         );
       });
    protocol::RedisRequest *req1 = redisTask1->get_req();
    req1->set_request("SET",{"54","ABC"});
    redisTask1->start();
    gWaitGroup.wait();
}

