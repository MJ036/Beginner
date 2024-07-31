#ifndef __PRODUCER_H__
#define __PRODUCER_H__


class TaskQueue;

#include "Thread.h"

class Producer
{
public:
    Producer();
    ~Producer();
    
    void producer(TaskQueue &taskQue);


    

};

#endif
