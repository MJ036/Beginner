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


int main()
{
    signal(SIGINT,handler);
    WFRedisTask *redisTask = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",0,
                                                        [](WFRedisTask *redisTask){
                                                              protocol::RedisRequest *req = redisTask->get_req();
                                                              protocol::RedisResponse *resp = redisTask->get_resp();
                                                              protocol::RedisValue value;
                                                              int state = redisTask->get_state();
                                                              int error = redisTask->get_error();
                                                              switch(state){
                                                              case WFT_STATE_SYS_ERROR:
                                                              cout << "system error:" << strerror(error) << "\n";
                                                              break;
                                                              case WFT_STATE_DNS_ERROR:
                                                              cout << "dns error: " << gai_strerror(error) << "\n";
                                                              break;
                                                              case WFT_STATE_SUCCESS:
                                                              resp->get_result(value); //将redis的结果已经存在value中了
                                                              if(value.is_error()){
                                                              cout << "redis error\n";
                                                              state = WFT_STATE_TASK_ERROR; // 任务层面的错误
                                                              }
                                                              break;
                                                              }
                                                              if(state == WFT_STATE_SUCCESS){
                                                                  cout << "SUCCESS\n";
                                                              }
                                                              else{
                                                                  cout << "FAILED\n";
                                                                  return;
                                                              }

                                                              if(value.is_string()){
                                                                  cout << "value is a string ,value = " << value.string_value() << "\n";    
                                                              }
                                                              else if(value.is_array()){
                                                                  for(size_t i = 0; i < value.arr_size(); ++i){
                                                                      cout << "value is arr , i =" << i << " , arr[i]= "  << value.arr_at(i).string_value() << "\n";
                                                                  }
                                                              }
                                                          }
    );
    //设置redisTask属性 请求
    protocol::RedisRequest * req = redisTask->get_req();

    req->set_request("GET",{"x"});
    /* req->set_request("HGETALL",{"h1"}); */
    //任务交给框架 异步调用
    redisTask->start();
    sleep(1);
    cout  << "3\n";
    //等待计数器为0
    gWaitGroup.wait();
}

