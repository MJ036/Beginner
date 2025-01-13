#include "func.h"

void copyFile_rw(const char* src,const char* dst){
    int fdr = open(src,O_RDONLY);
    int fdw = open(dst,O_WRONLY | O_CREAT,0666);

    int bytes;
    char buf[4096];
    while((bytes = read(fdr,buf,sizeof(bytes))) > 0){
        write(fdw,buf,bytes);
    }

    close(fdr);
    close(fdw);
}

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);

    copyFile_rw(argv[1],argv[2]);

    return 0;
}

