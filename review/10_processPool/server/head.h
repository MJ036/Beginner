#include "func.h"
enum{
    FREE,
    BUSY
};

typedef struct workerdata_s{
    pid_t pid;
    int status;
    int pipesocketfd;
}workerdata_t;

int makeWorker(int workerNum,workerdata_t *workerArr);
int tcpInit(const char *ip, const char *port,int *psockfd);
int epollAdd(int epfd, int fd);
int epollDel(int epfd, int fd);
int sendfd(int fd, int fdtosend, int exitFlag);
int recvfd(int fd, int *fdtorecv, int *exitFlag);
int transFile(int fd);
int workLoop(int sockfd);
