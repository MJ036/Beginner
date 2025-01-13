#include "threadpool.h"
#include "transFile.h"

int queueInit(task_queue_t *que){
    if(que){
        que->pFront = NULL;
        que->pRear = NULL;
        que->queSize = 0;
        que->flag = 1;
        int ret = pthread_mutex_init(&que->mutex,NULL);
        THREAD_ERROR_CHECK(ret,"pthread_mutex_init");
        ret = pthread_cond_init(&que->cond,NULL);
        THREAD_ERROR_CHECK(ret,"pthread_cond_init");
    }
    return 0;
}
int queueDestory(task_queue_t *que){
    if(que){
        int ret = pthread_mutex_destroy(&que->mutex);
        THREAD_ERROR_CHECK(ret,"pthread_mutex_destroy");
        ret = pthread_cond_destroy(&que->cond);
        THREAD_ERROR_CHECK(ret,"pthread_cond_destroy");
    }
    return 0;
}
int queueIsEmpty(task_queue_t *que){
    return que->queSize == 0;
}
int taskSize(task_queue_t *que){
    return que->queSize;
}
int taskEnque(task_queue_t *que,int peerfd){
    task_t * pNode = (task_t *)calloc(1,sizeof(task_t));
    pNode->peerfd = peerfd;
    pNode->pNext = NULL;
    int ret = pthread_mutex_lock(&que->mutex);
    THREAD_ERROR_CHECK(ret,"pthread_mutex_lock");
    if(queueIsEmpty(que)){
        que->pFront = que->pRear = pNode;
    }else{
        que->pRear->pNext = pNode;
        que->pRear = pNode;
    }
    que->queSize++;
    puts("taskEnque success");
    ret = pthread_cond_signal(&que->cond);
    THREAD_ERROR_CHECK(ret,"pthread_cond_signal");
    puts("cond_signal");

    ret = pthread_mutex_unlock(&que->mutex);
    THREAD_ERROR_CHECK(ret,"pthread_mutex_unlock");

    return 0;
}
int taskDeque(task_queue_t *que){
    int ret = pthread_mutex_lock(&que->mutex);
    THREAD_ERROR_CHECK(ret,"pthread_mutex_lock");
    int peerfd = -1;
    //when que not empty, wake up. if empty ,wait 
    while(que->flag && queueIsEmpty(que)){
        pthread_cond_wait(&que->cond,&que->mutex);
    }
    if(que->flag){
        peerfd = que->pFront->peerfd;
        task_t *pDelete = que->pFront;
        if(taskSize(que) == 1){
            que->pFront = que->pRear = NULL;
        }else{
            que->pFront = que->pFront->pNext;
        }
        free(pDelete);
        que->queSize--;
    }else{
        peerfd = -1;
    }
    ret = pthread_mutex_unlock(&que->mutex);
    THREAD_ERROR_CHECK(ret,"pthread_mutex_unlock");
    return peerfd;
}
int broadcastAll(task_queue_t *que){
    que->flag = 0;
    int ret = pthread_cond_broadcast(&que->cond);
    THREAD_ERROR_CHECK(ret,"pthread_cond_broadcast");
    return 0;
}

int threadpoolInit(thread_pool_t *pthreadpool, int num){
    pthreadpool->pthreadNum = num;
    pthreadpool->pthreads =(pthread_t*)calloc(num,sizeof(pthread_t));
    queueInit(&pthreadpool->que);
    return 0;
}
int threadpoolDestory(thread_pool_t *pthreadpool){
    free(pthreadpool->pthreads);
    queueDestory(&pthreadpool->que);
    return 0;
}

void *threadFunc(void *arg){
    thread_pool_t *pThreadpool = (thread_pool_t*)arg;
    while(1){
        printf("sub thread %ld ready to get task.\n",pthread_self());
        int peerfd = taskDeque(&pThreadpool->que);
        printf("after taskEnque: que.flag = %d\n,",pThreadpool->que.flag);
        printf("peerfd = %d,sub thread %ld get task.\n",peerfd,pthread_self());
        if(peerfd > 0){
            puts("transFile");
            transFile(peerfd);
        }else{
            break;
        }
    }
    printf("sub thread %ld is finished.\n",pthread_self());
    return NULL;
}

int threadpoolStart(thread_pool_t *pthreadpool){
    if(pthreadpool){
        for(int i = 0; i < pthreadpool->pthreadNum; ++i){
            int ret = pthread_create(&pthreadpool->pthreads[i],NULL,threadFunc,pthreadpool);
            THREAD_ERROR_CHECK(ret,"pthread_create");
            printf("pthread:%d is created!\n",i);
        }
    }
    return 0;
}
int threadpoolStop(thread_pool_t *pthreadpool){
    while(!queueIsEmpty(&pthreadpool->que)){
        sleep(1);
    }
    broadcastAll(&pthreadpool->que);
    for(int i = 0; i < pthreadpool->pthreadNum; i++){
        pthread_join(pthreadpool->pthreads[i],NULL);
    }
    return 0;
}
