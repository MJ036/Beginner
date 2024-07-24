#include "TaskQueue.h"

TaskQueue::TaskQueue(size_t queSize)
    :_queSize(queSize)
     ,_que()
     ,_mutex()
     ,_notFull()
     ,_notEmpty()
{}

TaskQueue::~TaskQueue(){

}

void TaskQueue::push(const int &value){
    unique_lock<mutex> autoLock(_mutex);
    while(full()){
        _notFull.wait(autoLock);
    }
    _que.push(value);
    _notEmpty.notify_one();
}

int TaskQueue::pop(){
    unique_lock<mutex> autoLock(_mutex);

    while(empty()){
        _notEmpty.wait(autoLock);
    }
    int temp = _que.front();
    _que.pop();
    _notFull.notify_one();
    return temp;
}

bool TaskQueue::empty() const {
    return _que.size() == 0;
}

bool TaskQueue::full() const {
    return _queSize == _que.size();
}



