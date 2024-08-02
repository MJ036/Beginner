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

int main()
{
    signal(SIGINT,handler);

    WFRedisTask *redisTask1 = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",1,
        [](WFRedisTask *redisTask){
            protocol::RedisRequest *req = redisTask->get_req();
            protocol::RedisResponse *resp = redisTask->get_resp();
            protocol::RedisValue value;
            //状态检查
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
                resp->get_result(value);
                if(value.is_error()){
                    cout << "redis error\n";
                    state = WFT_STATE_TASK_ERROR;
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
                cout << "value is a string, value = " << value.string_value() << "\n";
            }
            else if(value.is_array()){
                for(size_t i = 0; i < value.arr_size();++i){
                    cout << "value is arr, i = " << i << " , arr[i] = " << value.arr_at(i).string_value() << "\n";
                }
            }
    });

    protocol::RedisRequest *req1 = redisTask1->get_req();
    req1->set_request("SET",{"54","RST"});

    WFRedisTask *redisTask2 = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",0,
           [](WFRedisTask *redisTask){
           protocol::RedisRequest * req = redisTask->get_req();
           protocol::RedisResponse * resp = redisTask->get_resp();
           protocol::RedisValue value; //将要用来获取redis返回的结果
           int state = redisTask->get_state();
           int error = redisTask->get_error(); //error只能处理网络连接和系统错误
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
               cout << "value is a string, value = " << value.string_value() << "\n";
           }
           else if(value.is_array()){ // 结果是一个字符串数组
               for(size_t i = 0; i < value.arr_size(); ++i){
                   cout << "value is arr, i = " << i << " , arr[i] = " << value.arr_at(i).string_value() << "\n";
               }
           }
           }
    );
    // 设置redisTask的属性 请求
    protocol::RedisRequest * req2 = redisTask2->get_req();
    req2->set_request("GET",{"54"});

    SeriesWork *series = Workflow::create_series_work(redisTask1,nullptr);
    series->push_back(redisTask2);
    series->start();
    gWaitGroup.wait();
}

