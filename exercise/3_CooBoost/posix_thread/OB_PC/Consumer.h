#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include "Thread.h"

class TaskQueue;

class Consumer
{
public:
    Consumer();
    ~Consumer();

    void consumer(TaskQueue &taskQue);


};

#endif
