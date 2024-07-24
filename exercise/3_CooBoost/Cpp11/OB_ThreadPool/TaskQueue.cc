#include "TaskQueue.h"

TaskQueue::TaskQueue(size_t queSize)
    :_queSize(queSize)
     ,_que()
     ,_mutex()
     ,_notFull()
     ,_notEmpty()
     ,_flag(true)
{}

TaskQueue::~TaskQueue(){

}

void TaskQueue::push(ElemType &&task){
    unique_lock<mutex> autoLock(_mutex);
    while(full()){
        _notFull.wait(autoLock);
    }
    _que.push(task);
    _notEmpty.notify_one();
}

ElemType TaskQueue::pop(){
    unique_lock<mutex> autoLock(_mutex);

    while(empty() && _flag){
        _notEmpty.wait(autoLock);
    }
    if(_flag){
        ElemType temp = _que.front();
        _que.pop();
        _notFull.notify_all();
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
    _notEmpty.notify_all();
}



