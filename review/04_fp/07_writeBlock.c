#include "mai.h"

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);
    int fdw = open(argv[1],O_RDWR);
    int fdr = open(argv[1],O_RDWR);
    ERROR_CHECK(fdr,-1,"read");
    ERROR_CHECK(fdw,-1,"write");


    char buf[128] = {0};
    fd_set rdset;
    fd_set wrset;
    int ret;

    while(1){
        FD_ZERO(&rdset);
        FD_SET(fdw,&wrset);
        FD_SET(fdr,&rdset);

        ret = select(fdr + 1,&rdset,&wrset,NULL,NULL);
        ERROR_CHECK(ret,-1,"select");

        if(FD_ISSET(fdr,&rdset)){
            memset(buf,0,sizeof(buf));
            ret = read(fdr,buf,sizeof(buf));
            if(ret == 0){
                break;
            }
            puts(buf);
            usleep(5000000);
        }

        if(FD_ISSET(fdw,&wrset)){
            printf("Ready to");
            ssize_t n =  write(fdw,"helloworld",10);
            printf("Already writed");
            ERROR_CHECK(n,-1,"write block");
            usleep(25000);

        }
    }
    return 0;
}

