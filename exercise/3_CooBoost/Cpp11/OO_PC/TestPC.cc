#include "Producer.h"
#include "Consumer.h"
#include "TaskQueue.h"
#include <iostream>
#include <memory>
#include <thread>


using std::cout;
using std::endl;
using std::thread;
using std::unique_ptr;

void test(){
    TaskQueue taskQue(10);


    Producer producer;
    Consumer consumer;
    thread pro(&Producer::produce,&producer,std::ref(taskQue));
    thread con(&Consumer::consumer,&consumer,std::ref(taskQue));

    pro.join();
    con.join();
}


int main()
{
    std::cout << "Hello world" << std::endl;
    test();
    return 0;
}

