#include"func.h"
typedef struct shareRes_s{
    pthread_mutex_t mutex;
} shareRes_t, *pShareRes_t;
void *threadFunc(void *arg){
    pShareRes_t p = (pShareRes_t)arg;
    pthread_mutex_lock(&p->mutex);
    puts("fifth");
    pthread_mutex_unlock(&p->mutex);
}
int main()
{
    shareRes_t shared;
    int ret;
    pthread_mutexattr_t mutexattr;
    pthread_mutexattr_init(&mutexattr);
    ret = pthread_mutexattr_settype(&mutexattr,PTHREAD_MUTEX_ERRORCHECK);
//    ret = pthread_mutexattr_settype(&mutexattr,PTHREAD_MUTEX_RECURSIVE);
    THREAD_ERROR_CHECK(ret,"pthread_mutexattr_settype");
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,(void *)&shared);
    pthread_mutex_init(&shared.mutex,&mutexattr);
    ret = pthread_mutex_lock(&shared.mutex);
    THREAD_ERROR_CHECK(ret,"pthread_mute_lock 1");
    puts("first");
    ret = pthread_mutex_lock(&shared.mutex);
    THREAD_ERROR_CHECK(ret,"pthread_mute_lock 2");
    puts("second");
    pthread_mutex_unlock(&shared.mutex);
    puts("third");
    pthread_mutex_unlock(&shared.mutex);//两次加锁，要有两次解锁
    puts("forth");
    pthread_join(tid,NULL);
    return 0;
}

