#include "mai.h"

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    int fdw = open(argv[1],O_WRONLY);
    int fdr = open(argv[2],O_RDONLY);
    ERROR_CHECK(fdr,-1,"read");
    ERROR_CHECK(fdw,-1,"write");

    printf("I am chat 2\n");
    printf("fdr = %d,fdw = %d\n",fdr,fdw);

    char buf[128] = {0};
    fd_set rdset;
    int ret;

    while(1){
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(fdr,&rdset);
        ret = select(fdr + 1,&rdset,NULL,NULL,NULL);
        ERROR_CHECK(ret,-1,"select");
        if(FD_ISSET(STDIN_FILENO,&rdset)){
            memset(buf,0,sizeof(buf));
            read(STDIN_FILENO,buf,sizeof(buf));
            write(fdw,buf,strlen(buf)-1);

        }
        if(FD_ISSET(fdr,&rdset)){
            memset(buf,0,sizeof(buf));
            read(fdr,buf,sizeof(buf));
            printf("buf = %s\n",buf);

        }
    }
    return 0;
}

