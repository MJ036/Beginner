#ifndef __WORKER__
#define __WORKER__

#include <func.h>
typedef struct tidArr_s{
    pthread_t *arr;
    int workerNum;
}tidArr_t;

typedef struct threadPool_s threadPool_t;

int tidArrInit(tidArr_t *, int workerNum);
int makeWorker(threadPool_t *);
void* threadFunc(void *arg);

#endif
