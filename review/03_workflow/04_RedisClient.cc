#include "mai.h"
#include <cstdio>
#include <hiredis/read.h>
#include <workflow/WFFacilities.h>
#include <workflow/WFTask.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/RedisMessage.h>
#include <workflow/Workflow.h>

#define RETRY_MAX 2
using namespace std;

struct tutorial_task_data{
    string url;
    string key;
};

static WFFacilities::WaitGroup wait_group(1);

void sig_handler(int signo){
    wait_group.done();
}

void callback(WFRedisTask *redisTask){
    protocol::RedisRequest *req  = redisTask->get_req();
    protocol::RedisResponse *resp = redisTask->get_resp();
    int state = redisTask->get_state();
    int error = redisTask->get_error();

    //用来获取redis任务的返回结果
    protocol::RedisValue val;

    switch(state){
    case WFT_STATE_SYS_ERROR:
        fprintf(stderr,"system error:%s\n",strerror(error));
        break;
    case WFT_STATE_DNS_ERROR:
        fprintf(stderr,"DNS error:%s\n",strerror(error));
        break;
    case WFT_STATE_SUCCESS:
        resp->get_result(val);
        if(val.is_error()){
            fprintf(stderr,"Error reply. need a password ?\n");
            state = WFT_STATE_TASK_ERROR;
        }
        break;
    }
    if(state !=WFT_STATE_SUCCESS){
        fprintf(stderr,"Failed. Press Ctrl-C to exit.\n");
        return;
    }

//    if(val.is_array()){
//        for(int i = 0; i < val.arr_size(); ++i){
//            auto ele = val.arr_at(i);
//            fprintf(stderr,"REDIS HGETALL %d = %s\n",i,ele.string_value().c_str());
//        }
//    }
    
    string cmd;
    req->get_command(cmd);
    if(cmd == "SET"){
        tutorial_task_data *data = (tutorial_task_data*)redisTask->user_data;
        auto next = WFTaskFactory::create_redis_task(data->url,RETRY_MAX,callback);
        next->get_req()->set_request("GET",{data->key});
        series_of(redisTask)->push_back(next);
        fprintf(stderr,"redis SET request success. Tring to GET...\n");
    }else if(cmd == "GET"){
        if(val.is_string()){
            fprintf(stderr,"Redis GET success. value = %s\n",val.string_value().c_str());

        }else{
            fprintf(stderr,"Error: Not a string value. \n");
        }
        fprintf(stderr,"Finished. Press Ctrl-C to exit.\n");

    }

}
int main()
{
    signal(SIGINT,sig_handler);

    //auto redisTask = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",2,callback);
    //protocol::RedisRequest *req = redisTask->get_req();
    //req->set_request("SET",{"mai","1"});
    //req->set_request("HSET",{"HMAP1","key1","value1"});
    //req->set_request("HGETALL",{"HMAP1"});

    struct tutorial_task_data data;
    data.url = "redis://127.0.0.1:6379";
    data.key = "key3";
    auto task = WFTaskFactory::create_redis_task(data.url,RETRY_MAX,callback);
    protocol::RedisRequest *req = task->get_req();
    req->set_request("SET",{data.key,"value3"});
    
    // task->user_data is a public (void *), can store anything.
    // 将url,需要查询的key包装起来，传递给回调函数
    task->user_data = &data;
    task->start();
    wait_group.wait();

    return 0;
}

