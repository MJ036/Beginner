#include "mai.h"

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    int fdr = open(argv[1],O_RDONLY);
    int fdw = open(argv[2],O_WRONLY);

    ERROR_CHECK(fdr,-1,"read");
    ERROR_CHECK(fdw,-1,"write");
    printf("I am chat 1\n");
    printf("fdr = %d,fdw = %d\n",fdr,fdw);

    char buf[128] = {0};
    while(1){
        memset(buf,0,sizeof(buf));
        read(STDIN_FILENO,buf,sizeof(buf));
        write(fdw,buf,strlen(buf)-1);
        memset(buf,0,sizeof(buf));
        read(fdr,buf,sizeof(buf));
        printf("buf = %s\n",buf);


    }

    return 0;
}

