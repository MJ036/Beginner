#include "taskQueue.h"
#include "func.h"
int taskQueueInit(taskQueue_t *ptaskQueue){
    bzero(ptaskQueue,sizeof(taskQueue_t));
    return 0;
}

int enQueue(taskQueue_t *ptaskQueue, int netfd){
    node_t *pnode = (node_t*)calloc(1,sizeof(node_t));
    pnode->netfd = netfd;
    if(ptaskQueue->queueSize == 0){
        ptaskQueue->pfront = pnode;
        ptaskQueue->prear = pnode;
    }else{
        ptaskQueue->prear->next = pnode;
        ptaskQueue->prear = pnode;
    }
    ptaskQueue->queueSize++;
    return 0;
}
int deQueue(taskQueue_t *ptaskQueue){
    node_t *cur = ptaskQueue->prear;
    ptaskQueue->prear = cur->next;
    if(ptaskQueue->queueSize == 1){
        ptaskQueue->prear = NULL;
    }   

    ptaskQueue->queueSize--;
    free(cur);
    return 0;
}
