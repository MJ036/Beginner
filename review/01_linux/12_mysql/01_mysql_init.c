#include "func.h"
#include <mysql/mysql.h>

int main(int argc, char* argv[])
{
    MYSQL* mysql = mysql_init(NULL);
    MYSQL* cret = mysql_real_connect(mysql,"localhost","root","123","test",0,NULL,0);
    if(cret == NULL){
        fprintf(stderr,"mysql_real_connect:%s\n",mysql_error(mysql));
        return -1;
    }
    char hid[] = "'4'";
    char name[] = "'Maijiabao'";
    char sql[4096] = {0};
    sprintf(sql,"insert into hero (hid,name) value(%s,%s);",hid,name);
    int qret = mysql_query(mysql,sql);
    if(qret != 0){
        fprintf(stderr,"mysql_query:%s\n",mysql_error(mysql));
        return -1;
    }
    
    return 0;
}

