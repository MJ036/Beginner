#include "worker.h"
#include "taskQueue.h"
#include "threadPool.h"
int tidArrInit(tidArr_t *tidArr, int workerNum){
    tidArr->arr = (pthread_t *)calloc(workerNum,sizeof(pthread_t));
    tidArr->workerNum = workerNum;
    return 0;
}

int makeWorker(threadPool_t * pthreadPool){
    for(int i = 0; i < pthreadPool->tidArr.workerNum; ++i){
        pthread_create(&pthreadPool->tidArr.arr[i],NULL,threadFunc,pthreadPool);
    }
    return 0;

}

void* threadFunc(void* arg){
    threadPool_t *pthreadPool = (threadPool_t*)arg;
    while(1){
        //puts("1");
        pthread_mutex_lock(&pthreadPool->mutex);
        while(pthreadPool->exitFlag == 0 && pthreadPool->taskQueue.queueSize <= 0){
        //puts("2");
            pthread_cond_wait(&pthreadPool->cond,&pthreadPool->mutex);

        //puts("3");
        //printf("flag = %d, queueSize = %d\n",pthreadPool->exitFlag,pthreadPool->taskQueue.queueSize);
        }
        //puts("4");
        if(pthreadPool->exitFlag == 1){
            puts("I am child , I am going to exit!");
            pthread_mutex_unlock(&pthreadPool->mutex);
            pthread_exit(NULL);
        }
        //puts("5");
        int netfd = pthreadPool->taskQueue.pfront->netfd;
        printf("I am worker, I got a netfd = %d\n", netfd);
        deQueue(&pthreadPool->taskQueue);
        pthread_mutex_unlock(&pthreadPool->mutex);
        transFile(netfd);
        close(netfd);

    }

}
