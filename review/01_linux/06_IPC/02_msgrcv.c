#include "func.h"

struct mymesg{
    long mtype;
    char mtext[64];
};

int main(int argc,char* argv[])
{
    int msgid = msgget(1000,IPC_CREAT | 0600);
    struct mymesg buf;
    int ret = msgrcv(msgid,&buf,sizeof(buf.mtext),0,0);
    printf("type = %ld, msg = %s\n",buf.mtype,buf.mtext);
    msgctl(msgid,IPC_RMID,NULL);

    

    return 0;
}

