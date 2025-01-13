#include "func.h"

struct mymesg{
    long mtype;
    char mtext[64];
};

int main(int argc,char* argv[])
{
    int msgid = msgget(1000,IPC_CREAT | 0600);
    struct mymesg buf;
    buf.mtype = 1;
    strcpy(buf.mtext,"hello");
    int ret = msgsnd(msgid,&buf,5,0);

    return 0;
}

