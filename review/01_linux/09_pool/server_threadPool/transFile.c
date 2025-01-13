#include "func.h"
#include "transFile.h"

// send 
int transFile(int netFd){
    train_t t = {5,"file2"};
    send(netFd,&t,sizeof(int)+ 5,MSG_NOSIGNAL);
    int fd = open(t.buf,O_RDONLY);
    ERROR_CHECK(fd,-1,"open");

    bzero(&t,sizeof(t));
    struct stat statbuf;
    fstat(fd,&statbuf);
    t.dataLength = sizeof(statbuf.st_size);
    memcpy(t.buf,&statbuf.st_size,sizeof(statbuf.st_size));
    send(netFd,&t,sizeof(int) + t.dataLength,MSG_NOSIGNAL);

    bzero(&t,sizeof(t));
    while(1){
        t.dataLength = read(fd,&t.buf,sizeof(t.buf));
        ERROR_CHECK(t.dataLength,-1,"read");
        //size  at last read
        if(t.dataLength != sizeof(t.buf)){
            printf("t.dataLength = %d\n",t.dataLength);
        }
        //if  file is read to end,send empty train
        if(t.dataLength == 0 ){
            bzero(&t,sizeof(t));
            send(netFd,&t,4,MSG_NOSIGNAL);
            break;
        }
        int ret = send(netFd,&t,sizeof(int) + t.dataLength,MSG_NOSIGNAL);
        if(ret == -1){
            perror("send");
            break;
        }
    }
    close(fd);
    return 0;
}

//多次mmap
int transFile_mmap_times(int netFd){
    train_t t = {5,"flie2"};
    send(netFd,&t,4+5,MSG_NOSIGNAL);
    int fd = open(t.buf,O_RDONLY);
    ERROR_CHECK(fd,-1,"open");

    bzero(&t,sizeof(t));
    struct stat statbuf;
    fstat(fd,&statbuf);
    off_t fileSize = statbuf.st_size;
    t.dataLength = sizeof(statbuf.st_size);
    memcpy(t.buf,&statbuf.st_size,sizeof(statbuf.st_size));
    send(netFd,&t,sizeof(int) + t.dataLength,MSG_NOSIGNAL);

    char *p = (char*)mmap(NULL,fileSize,PROT_READ,MAP_SHARED,fd,0);

    bzero(&t,sizeof(t));
    off_t total = 0;
    while(total < fileSize){
        if(fileSize - total >(off_t)sizeof(t.buf)){
            t.dataLength = sizeof(t.buf);
        }else{
            t.dataLength = fileSize -total;
        }
        memcpy(t.buf,p + total,t.dataLength);
        total += t.dataLength;
        int ret = send(netFd,&t,sizeof(int) + t.dataLength,MSG_NOSIGNAL);
        if(ret == -1){
            perror("send");
            break;
        }
    }
    t.dataLength = 0;
    send(netFd,&t,4,MSG_NOSIGNAL);

    munmap(p,fileSize);
    close(fd);
    return 0;
}

//mmap one time
int transFile_mmap(int netFd){
    train_t t = {5,"file2"};
    send(netFd,&t,4+5,MSG_NOSIGNAL);
    int fd = open(t.buf,O_RDWR);


    bzero(&t,sizeof(t));
    struct stat statbuf;
    int ret = fstat(fd,&statbuf);
    ERROR_CHECK(ret,-1,"fstat");
    off_t fileSize = statbuf.st_size;
    t.dataLength = sizeof(statbuf.st_size);
    memcpy(t.buf,&statbuf.st_size,t.dataLength);
    send(netFd,&t,sizeof(int) + t.dataLength,MSG_NOSIGNAL);

    char *p =(char*)mmap(NULL,fileSize,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
    ERROR_CHECK(p,MAP_FAILED,"mmap");
    send(netFd,p,fileSize,MSG_NOSIGNAL);

    bzero(&t,sizeof(t));
    send(netFd,&t,4,MSG_NOSIGNAL);

    munmap(p,fileSize);
    close(fd);

    return 0;
}    

