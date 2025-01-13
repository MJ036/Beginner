#include "func.h"

typedef struct{
    long long left;
    long long right;
}Section;

void* Func(void* arg){
    Section *sec =(Section*)arg;
    long long sum = 0;
    for(int i = sec->left; i <= sec->right; ++i){
        sum += i;
    }
    return (void*)sum;

}

int main(int argc,char* argv[])
{
    long long n;
    printf("Please input a long long int: ");
    scanf("%lld", &n);
    Section sec1,sec2;
    sec1 = {1,n/2};
    sec2 = {n/2 + 1,n};
 
    // 创建两个线程
    // 第一个线程对区间[1,n/2]累加
    pthread_t tid1,tid2;
    int ret;
    ret = pthread_create(&tid1,NULL,Func,&sec1);
    THREAD_ERROR_CHECK(ret,"pthread_create 1");
    // 第二个线程对区间(n/2, n]累加
    ret = pthread_create(&tid2,NULL,Func,&sec2);
    THREAD_ERROR_CHECK(ret,"pthread_create 2");

    // 主线乘等待两个子线程结束，并接收它们计算的结果。
    long long sum = 0;
    long long retval;
    ret = pthread_join(tid1,(void**)&retval);
    THREAD_ERROR_CHECK(ret,"join tid1");
    sum += retval;
    ret = pthread_join(tid2,(void**)&retval);
    THREAD_ERROR_CHECK(ret,"join tid2");
    sum += retval;
    // 输出最终结果。
    printf("sum = %lld\n",sum);
 
    return 0;
}

