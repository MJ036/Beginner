#include "func.h"

typedef struct{
    int dataLength;
    char buf[1000];
}train_t;

enum workerStatus{
    FREE,
    BUSY
};

typedef struct{
    pid_t pid;
    int pipeFd;
    int status;
}processData_t;

int makeChild(processData_t *pProcessData, int processNum);
void handleEvent(int pipeFd);

int tcpInit(char *ip, char *port, int *pSockFd);
int epollCtor();
int epollAdd(int fd, int epfd);

int recvFd(int pipeFd,int *pFd,int *exitFlag);
int sendFd(int pipeFd, int fdTosend,int exitFlag);
int transFile(int netFd);
int transFile_mmap_times(int netFd);
int transFile_mmap(int netfd);
