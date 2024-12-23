#include "func.h"

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,1);
    if(fork() == 0){
        //子进程
        printf("I am child\n");
        char buf[PATH_MAX];
        getcwd(buf,sizeof(buf));
        printf("pid = %d, before pwd = %s\n",getpid(), buf);
        chdir("..");
        getcwd(buf,sizeof(buf));
        printf("pid = %d, after pwd = %s\n",getpid(), buf);

        _exit(0);

    }else{
        //父进程
        printf("I am father\n");
        char buf[PATH_MAX];
        getcwd(buf,sizeof(buf));
        printf("parent before pwd = %s\n",buf);
        sleep(5);
        getcwd(buf,sizeof(buf));
        printf("parent after pwd = %s\n",buf);
        
        exit(0);

    }

    return 0;
}

