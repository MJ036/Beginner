#include "mai.h"
#include <csignal>
#include <nlohmann/json.hpp>
#include <unistd.h>
#include <wfrest/HttpDef.h>
#include <wfrest/HttpMsg.h>
#include <workflow/WFFacilities.h>
#include <wfrest/HttpServer.h>
#include <wfrest/Json.h>
#include <workflow/MySQLUtil.h>
#include <workflow/MySQLResult.h>
#include <workflow/WFGlobal.h>
#include <workflow/WFTask.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/Workflow.h>
#include <workflow/mysql_types.h>

using namespace std;
static WFFacilities::WaitGroup waitGroup(1);

void sigHander(int num){
    printf("sig %d is coming\n",num);
    waitGroup.done();
}

int main()
{
    signal(SIGINT,sigHander);
    using namespace wfrest;
    HttpServer httpserver;

    httpserver.GET("/wfrest/test0",[](const HttpReq *,HttpResp *resp){
                   resp->append_output_body("hello, wfrest client");
                   });
    httpserver.GET("/wfrest/query",
                   [](const HttpReq *req, HttpResp *resp){
                   cout << "username:" << req->query("username") << endl;
                   auto queryList = req->query_list();
                   for(auto &query : queryList){
                        cout << query.first << ": " << query.second << endl; 
                   }
                   resp->append_output_body("hello, wfrest client");
                   });
    httpserver.POST("/wfrest/body",
                    [](const HttpReq *req, HttpResp *resp){
                    string body = req->body();
                    cout << "body:" << body << endl; 
                    resp->append_output_body("hello, wfrest client");
                    });
    httpserver.POST("/wfrest/urlencoded",
                    [](const HttpReq *req, HttpResp *resp){
                    if(req->content_type() == wfrest::APPLICATION_URLENCODED){
                    auto formKV = req->form_kv();
                    for(auto &elem : formKV){
                        cout << elem.first << ": " << elem.second << endl;
                    }
                    }
                    resp->append_output_body("hello, wfrest client");
                    });
    httpserver.POST("/wfrest/formdata",
                    [](const HttpReq *req, HttpResp *resp){
                    if(req->content_type() == wfrest::MULTIPART_FORM_DATA){
                    auto form = req->form();
                    for(auto &elem : form){
                    cout << elem.first << ": " << elem.second.second << endl;
                    }
                    }

                   resp->append_output_body("hello, wfrest client");
                    });
    httpserver.GET("/wfrest/file",
                   [](const HttpReq *,HttpResp *resp)
                   {
                    resp->File("postform.html");
                   });
    httpserver.GET("/wfrest/json",
                   [](const HttpReq *,HttpResp *resp)
                   {
                   Json data;
                   data["username"] = "liubei";
                   data["password"] = "123";
                   resp->Json(data);
                   });
    httpserver.GET("/wfrest/mysql0",
                   [](const HttpReq *,HttpResp *resp)
                   {
                   string url("mysql://root:11111111@localhost");
                   string sql("select * from my_test.Student");
                   resp->MySQL(url,sql);
                   });
    httpserver.GET("/wfrest/mysql1", [](const HttpReq *req, HttpResp *resp)
                   {
                   string url = "mysql://root:11111111@localhost";
                   string sql("select * from my_test.Student");
                   resp->MySQL(url, sql, [resp](Json *json) 
                               {
                               Json js;
                               js = (*json)["result_set"][0]["rows"];
                               resp->Json(js);
                               cout << js.dump() << endl;
                               string msg = (*json)["result_set"][0]["rows"][0][1];
                               cout << "msg : " << msg << endl;
                               resp->String(msg);
                               });
                   });
    httpserver.GET("/wfrest/mysql2",
                   [](const HttpReq *,HttpResp *resp){
                   string url("mysql://root:11111111@localhost");
                   string sql("select * from my_test.Student");
                   resp->MySQL(url,sql,[resp](protocol::MySQLResultCursor *pcursor){
                               vector<vector<protocol::MySQLCell>> matrix;
                               pcursor->fetch_all(matrix);
                               string msg = matrix[0][2].as_string();
                               resp->String(msg);
                               });
                   });
    httpserver.GET("/wfrest/series",
                   [](const HttpReq *,HttpResp *resp,SeriesWork *series)
                   {
                   auto timerTask = WFTaskFactory::create_timer_task(1000 * 1000,[resp](WFTimerTask*){
                                                                     printf("timerCallback is runing");
                                                                     resp->String("timer callback");
                                                                     });
                   series->push_back(timerTask);
                   });
    httpserver.GET("/wfrest/mysql3",
                   [](const HttpReq *,HttpResp *resp)
                   {

                   });
    httpserver.GET("/wfrest/file",
                   [](const HttpReq *,HttpResp *httpResp, SeriesWork *series)
                   {
                   string url("mysql://root:11111111@localhost");
                   auto mysqlTask = WFTaskFactory::create_mysql_task(url,1,[httpResp](WFMySQLTask *mysqlTask){

                                                                     //检查任务状态
                                                                     int state = mysqlTask->get_state();
                                                                     int error = mysqlTask->get_error();
                                                                     if(state != WFT_STATE_SUCCESS){
                                                                     cerr << WFGlobal::get_error_string(state,error) << endl;;
                                                                     return;
                                                                     }
                                                                     //检查SQL是否有语法错误
                                                                     auto resp = mysqlTask->get_resp();
                                                                     if(resp->get_packet_type() == MYSQL_PACKET_ERROR){
                                                                     cout << "ERROR " << resp->get_error_code()  << ": " << resp->get_error_msg().c_str();
                                                                     }return;

                                                                     cout << "sql sentence is ok." << endl;
                                                                     using namespace protocol;
                                                                     MySQLResultCursor cursor(resp);
                                                                     if(cursor.get_cursor_status() == MYSQL_STATUS_OK){
                                                                     cout << "Query OK." << cursor.get_affected_rows() << " row affected." << endl;
                                                                     }else if(cursor.get_cursor_status() == MYSQL_STATUS_GET_RESULT){
                                                                         vector<vector<MySQLCell>> matrix;
                                                                         cursor.fetch_all(matrix);
                                                                         string msg = matrix[1][1].as_string();
                                                                         httpResp->String(msg);
                                                                     }
                   });
                   string sql("select * from my_test.Student");
                   mysqlTask->get_req()->set_query(sql);
                   series->push_back(mysqlTask);
                   });

    if(httpserver.track().start(1234) == 0){
        httpserver.list_routes();
        waitGroup.wait();
        httpserver.stop();
    }else{
        printf("HttpServer start failed.\n");
    }

    return 0;
}

