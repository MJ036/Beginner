#include <mai.h>
#include <iostream>
#include <workflow/WFFacilities.h>
#include <workflow/MySQLUtil.h>
#include <workflow/MySQLResult.h>
#include <workflow/MySQLMessage.h>
#include <wfrest/HttpServer.h>
#include <wfrest/json.hpp>
using namespace std;

static WFFacilities::WaitGroup gWaitGroup(1);
void handler(int signum){
    printf("signum = %d\n",signum);
    gWaitGroup.done();
}

int main()
{
    signal(SIGINT,handler);
    using namespace wfrest;
    HttpServer server;
    server.GET("/abc",[](const HttpReq *req,HttpResp *resp){
                    resp->headers["key"] = "value";
               });
    server.POST("/def",[](const HttpReq *req,HttpResp *resp){
                if(req->content_type() == APPLICATION_URLENCODED){
                    map<string,string> body = req->form_kv();
                    for(auto &myPair:body){
                        cerr << "key = " << myPair.first << ", value = " << myPair.second << "\n"; 
                    }
                }
                });
    server.GET("/postform.html",[](const HttpReq *req,HttpResp *resp){
                    resp->File("postform.html");
               });
    
    server.Static("/static","./static_res/html/html2");
    server.POST("/formdata",[](const HttpReq *req,HttpResp *resp){
                if(req->content_type() == MULTIPART_FORM_DATA){
                    map<string,pair<string,string>> &formdata = req->form();
                    for(auto &myPair : formdata){
                        cerr << "key = " << myPair.first
                            << ", value1 = " << myPair.second.first
                            << ", value2 = " << myPair.second.second << "\n";
                    }
                }
             });
    server.GET("/upload",[](const HttpReq *req,HttpResp *resp){
               resp->File("upload.html");
               });
    server.POST("/upload",[](const HttpReq *req,HttpResp *resp){
                if(req->content_type() == MULTIPART_FORM_DATA){
                    map<string,pair<string,string>> &formdata = req->form();
                    for(auto &myPair : formdata){
                        cerr << "key = " << myPair.first
                            << ", value1 = " << myPair.second.first
                            << ", value2 = " << myPair.second.second << "\n";
                    }
                }
                });
    server.GET("/mysql",[](const HttpReq *req,HttpResp *resp){
                resp->MySQL("mysql://root:123456@localhost","select * from clouddisk.tbl_user_token;");
               });
    server.GET("/mysql1",[](const HttpReq *req,HttpResp *resp,SeriesWork *series){
                WFMySQLTask *mysqlTask =
                     WFTaskFactory::create_mysql_task("mysql://root:123456@localhost", 0,
        [](WFMySQLTask *mysqlTask){
            if (mysqlTask->get_state() != WFT_STATE_SUCCESS)
            {
                // 检查连接和权限的错误
                cerr << "error code = " << mysqlTask->get_error()
                    << ", msg = " << WFGlobal::get_error_string(mysqlTask->get_state(), mysqlTask->get_error());
                return;
            }
            // 检查mysql语法错误
            protocol::MySQLResponse *resp = mysqlTask->get_resp();
            if (resp->get_packet_type() == MYSQL_PACKET_ERROR)
            {
                cerr << "mysql error = " << resp->get_error_msg() << "\n";
                return;
            }

            // 获取执行的结果
            // 创建一个cursor
            protocol::MySQLResultCursor cursor(resp);
            do
            {
                if (cursor.get_cursor_status() == MYSQL_STATUS_OK)
                {
                    // 这是一个写任务
                    cerr << "affected rows = " << cursor.get_affected_rows() << "\n";
                }
                else
                {
                    vector<vector<protocol::MySQLCell>> rows;
                    cursor.fetch_all(rows);
                    for (auto &row : rows)
                    {
                        for (auto &cell : row)
                        {
                            if (cell.is_int())
                            {
                                cerr << cell.as_int();
                            }
                            else if (cell.is_ulonglong())
                            {
                                cerr << cell.as_ulonglong();
                            }
                            else if (cell.is_string())
                            {
                                cerr << cell.as_string();
                            }
                            else if (cell.is_datetime())
                            {
                                cerr << cell.as_datetime();
                            }
                            cerr << " ";
                        }
                        cerr << "\n";
                    }
                }
            } while (cursor.next_result_set());
        }); 
        mysqlTask->get_req()->set_query("select * from clouddisk.tbl_user_token;");
        series->push_back(mysqlTask);
               });
    


    if(server.start(1234) == 0){
        server.list_routes();
        gWaitGroup.wait();
        server.stop();
    }
}

