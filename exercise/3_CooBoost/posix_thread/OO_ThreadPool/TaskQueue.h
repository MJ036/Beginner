#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include"MutexLock.h"
#include"Condition.h"
#include<queue>

using std::queue;

class Task;

using ElemType = Task *;

class TaskQueue
{
public:
    TaskQueue(size_t queSize);
    ~TaskQueue() ;

    void push(ElemType ptask);

    ElemType pop();

    bool full() const;
    bool empty() const;

    void wakeup();

private:
    size_t _queSize;
    queue<ElemType> _que;
    MutexLock _mutex;
    Condition _notFull;
    Condition _notEmpty;
    bool _flag;

};

#endif
