#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include <mutex>
#include <condition_variable>
#include<queue>

using std::queue;
using std::mutex;
using std::unique_lock;
using std::condition_variable;

class TaskQueue
{
public:
    TaskQueue(size_t queSize);
    ~TaskQueue() ;

    void push(const int &value);

    int pop();

    bool full() const;
    bool empty() const;

private:
    size_t _queSize;
    queue<int> _que;
    mutex _mutex;
    condition_variable _notFull;
    condition_variable _notEmpty;

};

#endif
