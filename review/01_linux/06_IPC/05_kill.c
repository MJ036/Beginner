#include "func.h"

int main(int argc,char* argv[])
{
    if(argc < 3){
        perror("argc");
        exit(0);
    }

    int signum;
    sscanf(argv[1],"%d",&signum);
    for(int i = 2; i < argc; i++){
        pid_t pid;
        sscanf(argv[i],"%d",&pid);
        int ret = kill(pid,signum);
        ERROR_CHECK(ret,-1,"kill");
    }

    return 0;
}

