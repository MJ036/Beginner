#include "Thread.h"
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

Thread::Thread(ThreadCallback &&cb)
    :_thid(0)
     ,_cb(std::move(cb))
     ,_isRuning(false){

     }

Thread::~Thread(){

}

void Thread::start(){
    int ret = pthread_create(&_thid,nullptr,threadFunc,this);
    if(ret){
        perror("pthread_create");
        return;
    }

    _isRuning = true;
}

void Thread::stop(){
    if(_isRuning){
        int ret = pthread_join(_thid,nullptr);
        if(ret)
        {
            perror("pthread_join");
            return;
        }

        _isRuning = false;
    }
}

void *Thread::threadFunc(void *arg){
    Thread *pth = static_cast<Thread*> (arg);
    if(pth){
        pth->_cb();
    }
    else{
        cout << "nullptr == pth" << endl;
    }

    pthread_exit(nullptr);
}


