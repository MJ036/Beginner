#include "func.h"

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,1);
    pid_t pid = fork();
    if(pid == 0){
        printf("child, pid = %d, ppid = %d, pgid = %d\n", getpid(), getppid(),
               getpgid(0));
        exit(0);
    }
    else{
        printf("parent, pid = %d, ppid = %d, pgid = %d\n", getpid(), getppid(),
               getpgid(0));
        wait(NULL);
        exit(0);
    }

    return 0;
}

