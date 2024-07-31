#include <mai.h>
#include <iostream>
#include <string>
#include <vector>
#include <workflow/WFFacilities.h>
#include <workflow/MySQLUtil.h>
#include <workflow/MySQLMessage.h>
#include <workflow/MySQLResult.h>
using namespace std;

static WFFacilities::WaitGroup gWaitGroup(1);

void handler(int signum){
    printf("signum = %d\n",signum);
    gWaitGroup.done();
}

void mysqlCallback(WFMySQLTask *mysqlTask){
    if(mysqlTask->get_state() != WFT_STATE_SUCCESS){
        cerr << "error code = " << mysqlTask->get_error()
            << ", msg = " << WFGlobal::get_error_string(mysqlTask->get_state(),mysqlTask->get_error());
        return;
    }
    
    protocol::MySQLResponse *resp = mysqlTask->get_resp();
    if(resp->get_packet_type() == MYSQL_PACKET_ERROR){
        cerr << "mysql error = " << resp->get_error_msg() << "\n";
        return;
    }

    protocol::MySQLResultCursor cursor(resp);
    do{
        if(cursor.get_cursor_status() == MYSQL_STATUS_OK){
            cerr << "affected rows = " << cursor.get_affected_rows() << "\n";
        }
        else{
            vector<vector<protocol::MySQLCell>> rows;
            cursor.fetch_all(rows);
            for(auto &row : rows){
                for(auto &cell : row){
                    if(cell.is_int()){
                        cerr << cell.as_int();
                    }
                    else if(cell.is_ulonglong()){
                        cerr << cell.as_ulonglong();
                    }
                    else if(cell.is_string()){
                        cerr << cell.as_string();
                    }
                    else if(cell.is_datetime()){
                        cerr << cell.as_datetime();
                    }
                    cerr << " ";
                }
                cerr << "\n";
            }
        }
    }while(cursor.next_result_set());
}


int main()
{
    signal(SIGINT,handler);
    WFMySQLTask *mysqlTask = 
        WFTaskFactory::create_mysql_task("mysql://root:123456@localhost",0,mysqlCallback);
    string sql = "insert into clouddisk.tbl_user_token values(4,'jia','hijklm');";
    sql += "select * from clouddisk.tbl_user_token;";
    protocol::MySQLRequest *req = mysqlTask->get_req();
    req->set_query(sql);
    mysqlTask->start();
    gWaitGroup.wait();
}

