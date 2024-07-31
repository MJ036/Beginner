#include "TaskQueue.h"

TaskQueue::TaskQueue(size_t queSize)
    :_queSize(queSize)
     ,_que()
     ,_mutex()
     ,_notFull(_mutex)
     ,_notEmpty(_mutex)
     ,_flag(true)
{}

TaskQueue::~TaskQueue(){

}

void TaskQueue::push(ElemType &&task){
    MutexLockGuard autoLock(_mutex);
    while(full()){
        _notFull.wait();
    }
    _que.push(task);
    _notEmpty.notify();
}

ElemType TaskQueue::pop(){
    MutexLockGuard autoLock(_mutex);

    while(empty() && _flag){
        _notEmpty.wait();
    }
    if(_flag){
        ElemType temp = _que.front();
        _que.pop();
        _notFull.notify();
        return temp;
    }else{
        return nullptr;
    }
}

bool TaskQueue::empty() const {
    return _que.size() == 0;
}

bool TaskQueue::full() const {
    return _queSize == _que.size();
}

void TaskQueue::wakeup(){
    _flag = false;
    _notEmpty.notifyAll();
}



