#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "TaskQueue.h"
#include <vector>
#include <memory>
#include <functional>
#include <thread>


using std::vector;
using std::function;
using std::thread;

using Task = function<void()>;


class ThreadPool
{
public:
    ThreadPool(size_t _threadNum, size_t _queSize);
    ~ThreadPool();

    void start();
    void stop();

    void addTask(Task &&task);
private:
    Task getTask();
    void doTask();

private:
    size_t _threadNum;
    size_t _queSize;
    vector<thread> _threads;
    TaskQueue _taskQue;
    bool _isExit;

};

#endif
