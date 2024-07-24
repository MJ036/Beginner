#include "Thread.h"
#include "Producer.h"
#include "Consumer.h"
#include "TaskQueue.h"
#include <iostream>
#include <memory>


using std::cout;
using std::endl;
using std::unique_ptr;

void test(){
    TaskQueue taskQue(10);
    Producer producer;
    Consumer consumer;

    unique_ptr<Thread> pro(new Thread(bind(&Producer::producer,&producer,std::ref(taskQue))));
    unique_ptr<Thread> con(new Thread(bind(&Consumer::consumer,&consumer,std::ref(taskQue))));

    pro->start();
    con->start();

    pro->stop();
    pro->stop();
}

void test2(){
    MutexLock mutex1;
    /* MutexLock mutex2 = mutex1; */

    MutexLock mutex3;
    /* mutex3 = mutex1; */
}

int main()
{
    std::cout << "Hello world" << std::endl;
    test();
    return 0;
}

