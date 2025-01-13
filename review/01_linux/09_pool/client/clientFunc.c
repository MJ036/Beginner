#include "clientFunc.h"

int recvn(int netFd,void* pstart, int len){
    int total = 0;
    int ret;
    char *p = (char*)pstart;
    while(total < len){
        ret = recv(netFd,p+total,len-total,0);
        total += ret;
    }
    return 0;
}

int recvFile(int netFd){
    train_t t;
    bzero(&t,sizeof(t));
    recvn(netFd,&t.dataLength,sizeof(int));
    recvn(netFd,t.buf,t.dataLength);
    int fd = open(t.buf,O_WRONLY | O_CREAT,0666);
    ERROR_CHECK(fd,-1,"open");

    off_t fileSize;
    bzero(&t,sizeof(t));
    recvn(netFd,&t.dataLength,sizeof(int));
    recvn(netFd,&fileSize,t.dataLength);
    
    //recv fileSize by many times
    off_t doneSize = 0;
    off_t lastSize = 0;
    off_t slice = fileSize/100;
    while(1){
        bzero(&t,sizeof(t));
        recvn(netFd,&t.dataLength,sizeof(int));
        if(t.dataLength == 0){
            break;
        }
        doneSize += t.dataLength;
        if(doneSize - lastSize >= slice){
            printf("%5.2lf%%\r",100.0*doneSize/fileSize);
            fflush(stdout);
            lastSize = doneSize;
        }
        recvn(netFd,&t.buf,t.dataLength);
        write(fd,t.buf,t.dataLength);
    }
    printf("100.00%%\n");
    close(fd);
    return 0;
}


int recvFile_mmp(int netFd){
    train_t t;
    bzero(&t,sizeof(t));
    //recv fileName
    recvn(netFd,&t.dataLength,sizeof(int));
    recvn(netFd,t.buf,t.dataLength);

    //create file
    int fd = open(t.buf,O_RDWR | O_CREAT,0666);
    ERROR_CHECK(fd,-1,"open");

    off_t fileSize;
    bzero(&t,sizeof(t));
    recvn(netFd,&t.dataLength,sizeof(int));
    recvn(netFd,&fileSize,t.dataLength);

    // recv by one time
    ftruncate(fd,fileSize);
    char *p = (char *)mmap(NULL,fileSize,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
    ERROR_CHECK(p,MAP_FAILED,"mmap"); 
    recvn(netFd,p,fileSize);
    printf("100.00%%\n");
    munmap(p,fileSize);
    close(fd);

    return 0;
}
