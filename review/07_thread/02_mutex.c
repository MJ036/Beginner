#include "func.h"

typedef struct shareRes_s{
    int val;
    pthread_mutex_t mutex;
}shareRes_t,*pshareRes_t;

void *threadFunc(void* arg){
    pshareRes_t pshared = (pshareRes_t)arg;
    for(int i = 0; i < 20000000; ++i){
        pthread_mutex_lock(&pshared->mutex);
        ++pshared->val;
        pthread_mutex_unlock(&pshared->mutex);
    }
}

int main(int argc,char* argv[])
{
    int ret;
    pthread_t pid;
    shareRes_t shareRes;
    shareRes.val = 0;
    ret = pthread_mutex_init(&shareRes.mutex,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_mutex_init");

    struct timeval begTime,endTime;
    gettimeofday(&begTime,NULL);
    ret = pthread_create(&pid,NULL,threadFunc,(void*)&shareRes);
    for(int i = 0; i < 20000000; ++i){
        pthread_mutex_lock(&shareRes.mutex);
        ++shareRes.val;
        pthread_mutex_unlock(&shareRes.mutex);
    }
    ret = pthread_join(pid,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_join");
    gettimeofday(&endTime,NULL);
    long avgtime = ((endTime.tv_sec - begTime.tv_sec)*1000000 + (endTime.tv_usec - begTime.tv_usec));
    printf("avg lock/unlock time = %ld\n",avgtime);
    printf("val = %d\n",shareRes.val);
    ret = pthread_mutex_destroy(&shareRes.mutex);
    THREAD_ERROR_CHECK(ret,"pthread_mutex_destroy");

    

    return 0;
}

