#ifndef __THREADPOOL__
#define __THREADPOOL__
#include "worker.h"
#include "taskQueue.h"
typedef struct threadPool_s{
    tidArr_t tidArr;
    taskQueue_t taskQueue;
    pthread_mutex_t mutex;
    pthread_cond_t cond;

    int exitFlag;
}threadPool_t;


int threadPoolInit(threadPool_t * pthreadPool,int workerNum);
int tcpInit(const char *ip, const char *port,int *psockfd);
int epollAdd(int epfd, int fd);
int epollDel(int epfd, int fd);
int transFile(int fd);

#endif
