#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include<queue>
#include <functional>
#include <mutex>
#include <condition_variable>

using std::queue;
using std::function;
using std::mutex;
using std::condition_variable;

using ElemType = function<void()>;
using std::mutex;
using std::unique_lock;

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
    mutex _mutex;
    condition_variable _notFull;
    condition_variable _notEmpty;
    bool _flag;

};

#endif
