#include "func.h"

pthread_mutex_t mutex;
void* func(void* arg){
    long long *value = (long long *)arg;
    pthread_mutex_lock(&mutex);
    int i = 10000000;
    while(i-- > 0){
    (*value)++;
    }
    pthread_mutex_unlock(&mutex);
    return NULL;

}

int main(int argc,char* argv[])
{
    long long* value = (long long*) calloc(1, sizeof(long long));

    pthread_mutex_init(&mutex,NULL);

    // 创建两个线程
    pthread_t tid1,tid2;
    int ret;
    ret = pthread_create(&tid1,NULL,func,value);
    THREAD_ERROR_CHECK(ret,"pthread_create tid1");
    // 第一个线程执行 (*value)++ 10000000次
    ret = pthread_create(&tid2,NULL,func,value);
    THREAD_ERROR_CHECK(ret,"pthread_create tid2");
    // 第二个线程叶执行 (*value)++ 10000000次
 
 
    // 主线乘等待两个子线程结束。并打印 *value 的值。
    ret = pthread_join(tid1,NULL);
    THREAD_ERROR_CHECK(ret,"thread_join tid1");
    ret = pthread_join(tid2,NULL);
    THREAD_ERROR_CHECK(ret,"thread_join tid2");

    printf("value  = %lld",*value);
    pthread_mutex_destroy(&mutex);
    free(value);
 
    return 0;
}

