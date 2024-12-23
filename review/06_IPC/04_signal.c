#include "func.h"

void handler(int signum){
    switch(signum){
    case SIGINT:
        printf("caught SIGINT\n");
        break;
    case SIGTSTP:
        printf("caught SIGTSTP\n");
        break;
    default:
        printf("caught other\n");
    }
}

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,1);
    signal(SIGINT,handler);
    signal(SIGTSTP,handler);
    signal(SIGQUIT,handler);

    printf("programing pid = %d runing...\n",getpid());
    for(;;){
        sleep(5);
    }
    

    return 0;
}

