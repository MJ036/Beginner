#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include <mutex>
#include <condition_variable>
#include<queue>

using std::mutex;
using std::unique_lock;
using std::condition_variable;
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
    mutex _mutex;
    condition_variable _notFull;
    condition_variable _notEmpty;
    bool _flag;

};

#endif
