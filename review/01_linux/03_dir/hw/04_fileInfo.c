#include "func.h"

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);

    int fd = open(argv[1],O_RDWR | O_TRUNC | O_CREAT,0666);
    ftruncate(fd,40959);
    lseek(fd,0,SEEK_END);
    write(fd,"Hello world",11);
    struct stat my_stat;
    fstat(fd,&my_stat);
    printf("File size: %ld bytes\n", my_stat.st_size);
    printf("Block size: %ld bytes\n", my_stat.st_blksize);
    printf("Allocated blocks: %ld\n", my_stat.st_blocks);


    close(fd);



    return 0;
}

