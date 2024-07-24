#include "ThreadPool.h"
#include "Task.h"
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

ThreadPool::ThreadPool(size_t threadNum, size_t queSize)
    :_threadNum(threadNum)
     ,_queSize(queSize)
     ,_taskQue(_queSize)
     ,_isExit(false)
{
    _threads.reserve(threadNum);
}

ThreadPool::~ThreadPool(){

}

void ThreadPool::start(){
    for(size_t idx = 0; idx != _threadNum; ++idx){
        _threads.push_back(thread(&ThreadPool::doTask,this));
        
    }

}

void ThreadPool::stop(){
    while(!_taskQue.empty()){
        sleep(1);
    }
    _isExit = true;

    _taskQue.wakeup();
    for(auto &th : _threads){
        th.join();
    }

}
void ThreadPool::addTask(Task *ptask){
    if(ptask){
        _taskQue.push(ptask);
    }
}

Task *ThreadPool::getTask(){
    return _taskQue.pop();
}

void ThreadPool::doTask(){
    while(! _isExit){
        Task *ptask = getTask();
        if(ptask){
            ptask->process();
        }else{
            cout << "nullptr == ptask" << endl;
        }
    }
}

