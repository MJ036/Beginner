#include "ThreadPool.h"
#include "Thread.h"

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
        _threads.push_back(unique_ptr<Thread>(new Thread(std::bind(&ThreadPool::doTask,this))));
    }

    for(auto &th : _threads){
        th->start();
    }
}

void ThreadPool::stop(){
    while(!_taskQue.empty()){
        sleep(1);
    }
    _isExit = true;

    _taskQue.wakeup();
    for(auto &th : _threads){
        th->stop();
    }

}
void ThreadPool::addTask(Task &&task){
    if(task){
        _taskQue.push(std::move(task));
    }
}

Task ThreadPool::getTask(){
    return _taskQue.pop();
}

void ThreadPool::doTask(){
    while(! _isExit){
        Task taskcb = getTask();
        if(taskcb){
            taskcb();
        }else{
            cout << "nullptr == ptask" << endl;
        }
    }
}

