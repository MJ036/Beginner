#ifndef __TASKQUEUE__
#define __TASKQUEUE__

typedef struct node_s{
    int netfd;
    struct node_s *next;
}node_t;

typedef struct taskQueue_s{
    node_t *pfront;
    node_t *prear;
    int queueSize;
}taskQueue_t;

int taskQueueInit(taskQueue_t *);
int enQueue(taskQueue_t *ptaskQueue, int netfd);
int deQueue(taskQueue_t *ptaskQueue);

#endif
