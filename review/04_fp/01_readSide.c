#include "mai.h"

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_RDONLY);
    ERROR_CHECK(fd,-1,"open");
    printf("fdr = %d\n",fd);

    char buf[128] = {0};
    read(fd,buf,sizeof(buf));
    printf("buf = %s\n",buf);

    return 0;
}

