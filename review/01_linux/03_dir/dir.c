#include "mai.h"

int main(int argc,char* argv[])
{
    DIR* pdir = opendir(".");
    ERROR_CHECK(pdir,NULL,"opendir");

    long loc = telldir(pdir);
    struct dirent* pdirent;
    errno = 0;
    while(1){
        long temloc = telldir(pdir);
        pdirent = readdir(pdir);
        if(pdirent == NULL){
            break;
        }
        printf("%s ",pdirent->d_name);
        if(strcmp(pdirent->d_name , "Makefile") == 0){
            loc = temloc;
        }
    }
    printf("\n");
    if(errno != 0){
        perror("readdir");
        exit(1);
    }
    printf("---------------------\n");

    seekdir(pdir,loc);
    pdirent = readdir(pdir);
    puts(pdirent->d_name);
    printf("---------------------\n");

    rewinddir(pdir);
    pdirent = readdir(pdir);
    puts(pdirent->d_name);
    closedir(pdir);
    printf("---------------------\n");
    printf("%d\n",errno);

    return 0;
}

