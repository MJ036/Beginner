#include "head.h"

typedef struct train_s{
    int length;
    char data[1000];
}train_t;

int transFile(int netfd){
    train_t train;
    char filename[] = "file1";
    train.length = strlen(filename);
    memcpy(train.data,filename,train.length);
    send(netfd,&train,train.length + sizeof(train.length),MSG_NOSIGNAL);

    struct stat statbuf;
    int fd = open(filename,O_RDWR);
    fstat(fd,&statbuf);
    train.length = sizeof(off_t);
    memcpy(train.data,&statbuf.st_size,train.length);
    send(netfd,&train,train.length + sizeof(train.length),MSG_NOSIGNAL);
    
    char *p = (char*)mmap(NULL,statbuf.st_size,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
    send(netfd,p,statbuf.st_size,MSG_NOSIGNAL);
    printf("done\n");
    munmap(p,statbuf.st_size);
    close(fd);

    return 0;
    
}
