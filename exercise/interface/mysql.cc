#include <mai.h>
#include <iostream>
#include <vector>
#include <workflow/WFFacilities.h>
#include <workflow/MySQLUtil.h>
#include <workflow/MySQLMessage.h>
#include <workflow/MySQLResult.h>
using std::string;
using std::cerr;
using std::vector;


static WFFacilities::WaitGroup gWaitGroup(1);
void handle(int signum){
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
        if(cur)
        
    }while(cursor.next_result_set());


    if(cursor.get_cursor_status() == MYSQL_STATUS_OK){
        cerr << "affected rows = " << cursor.get_affected_rows() << "\n";
        return;
    }
    else{
        vector<vector<protocol::MySQLCell>> rows;
        cursor.fetch_all(rows);
        for(auto &rows : rows){
            for(auto &cell : rows){
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
        }
    }
}

int main()
{
    signal(SIGINT,handler);
    WFMySQLTask *mysqlTask =
        WFTaskFactory::create_mysql_task("mysql://root:123@localhost",0,mysqlCallback);


    return 0;
}

