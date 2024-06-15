#include "TaskQueue.h"

TaskQueue::TaskQueue(size_t queSize)
    :_queSize(queSize)
     ,_que()
     ,_mutex()
     ,_notFull(_mutex)
     ,_notEmpty(_mutex)
{}

TaskQueue::~TaskQueue(){

}

void TaskQueue::push(const int &value){
    MutexLockGuard autoLock(_mutex);
    while(full()){
        _notFull.wait();
    }
    _que.push(value);
    _notEmpty.notify();
}

int TaskQueue::pop(){
    MutexLockGuard autoLock(_mutex);

    while(empty()){
        _notEmpty.wait();
    }
    int temp = _que.front();
    _que.pop();
    _notFull.notify();
    return temp;
}

bool TaskQueue::empty() const {
    return _que.size() == 0;
}

bool TaskQueue::full() const {
    return _queSize == _que.size();
}



