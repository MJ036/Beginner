#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include"MutexLock.h"
#include"Condition.h"
#include<queue>
#include <functional>

using std::queue;
using std::function;


using ElemType = function<void()>;

class TaskQueue
{
public:
    TaskQueue(size_t queSize);
    ~TaskQueue() ;

    void push(ElemType &&task);

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
