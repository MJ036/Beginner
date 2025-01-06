#include "func.h"

typedef struct task_s{
    int peerfd;
    struct task_s *pNext;
}task_t;

typedef struct task_queue_s{
     task_t *pFront;
     task_t *pRear;
     int queSize;

     pthread_mutex_t mutex;
     pthread_cond_t cond;
     int flag;
}task_queue_t;

typedef struct thread_pool_s{
    pthread_t *pthreads;
    int pthreadNum;
    task_queue_t que;
}thread_pool_t;


//operation of task_queue
int queueInit(task_queue_t *que);
int queueDestory(task_queue_t *que);
int queueIsEmpty(task_queue_t *que);
int taskSize(task_queue_t *que);
int taskEnque(task_queue_t *que,int peerfd);
int taskDeque(task_queue_t *que);
int broadcastAll(task_queue_t *que);

// operation of thread_pool
int threadpoolInit(thread_pool_t *, int num);
int threadpoolDestory(thread_pool_t *);
int threadpoolStart(thread_pool_t *);
int threadpoolStop(thread_pool_t *);

