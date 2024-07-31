#include <mai.h>
#include <iostream>
#include <workflow/WFFacilities.h>
#include <wfrest/HttpServer.h>

using namespace std;
static WFFacilities::WaitGroup gWaitGroup(1); 
// 阻塞主线程，直到按下ctrl+c
void handler(int signum){
    printf("signum = %d\n", signum);
    gWaitGroup.done(); //计数器减一
}

int main()
{
    signal(SIGINT,handler);
    wfrest::HttpServer server;
    server.POST("/abc",[](const wfrest::HttpReq *req, wfrest::HttpResp *resp){
                resp->headers["Location"] = "/xyz";
                resp->append_output_body("123");
                });
    server.POST("/xyz",[](const wfrest::HttpReq *req, wfrest::HttpResp *resp){
                resp->append_output_body("789");
                });
    server.POST("/login",[](const wfrest::HttpReq *req, wfrest::HttpResp *resp,SeriesWork *series){
                std::map<string,string> queryMap = req->query_list();
                string user = queryMap["user"];
                string password = queryMap["password"];
                cerr << "user = " << user << ", password = " << password << "\n";
                WFRedisTask *redisTask = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",0,
                                                                          [=](WFRedisTask *redisTask){
                                                                          protocol::RedisResponse *redisResp = redisTask->get_resp();
                                                                          protocol::RedisValue value;
                                                                          redisResp->get_result(value);
                                                                          if(value.is_string() && value.string_value() == password){
                                                                          resp->String("OK");
                                                                          }
                                                                          else{
                                                                          resp->String("NO");
                                                                          }
                                                                          }
                                                                          );
                redisTask->get_req()->set_request("HGET",{"54user",user});
                series->push_back(redisTask);
                });
        

                if(server.start(1234) == 0 ){
                server.list_routes();
                gWaitGroup.wait();
                server.stop();
                }
}

