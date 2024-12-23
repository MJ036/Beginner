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
    while(1){
        memset(buf,0,sizeof(buf));
        read(fdr,buf,sizeof(buf));
        printf("buf = %s\n",buf);
        memset(buf,0,sizeof(buf));
        read(STDIN_FILENO,buf,sizeof(buf));
        write(fdw,buf,strlen(buf)-1);



    }

    return 0;
}

