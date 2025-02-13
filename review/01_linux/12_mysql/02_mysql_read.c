#include "func.h"
#include <mysql/mysql.h>

int main(int argc, char* argv[])
{
    MYSQL* mysql = mysql_init(NULL);
    MYSQL* cret = mysql_real_connect(mysql,"localhost","root","11111111","my_test",0,NULL,0);
    if(cret == NULL){
        fprintf(stderr,"mysql_real_connect:%s\n",mysql_error(mysql));
        return -1;
    }
    char sql[4096] = "select * from Student;";
    int qret = mysql_query(mysql,sql);
    if(qret != 0){
        fprintf(stderr,"mysql_query:%s\n",mysql_error(mysql));
        return -1;
    }
    MYSQL_RES *res = mysql_store_result(mysql);
    printf("total row = %lu, total col = %d\n",mysql_num_rows(res),mysql_num_fields(res));
    MYSQL_ROW row;
    while((row = mysql_fetch_row(res)) != NULL){
        for(unsigned int i = 0; i < mysql_num_fields(res); ++i){
            printf("%s\t",row[i]);
        }
        printf("\n");
    }
    mysql_close(mysql);
    return 0;
}

