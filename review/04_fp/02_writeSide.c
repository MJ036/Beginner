#include "mai.h"

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_WRONLY);
    ERROR_CHECK(fd,-1,"open");
    printf("fdw = %d\n",fd);

    char buf[128] = "helloworld";
    write(fd,buf,strlen(buf));
    printf("buf = %s\n",buf);
    return 0;
}

