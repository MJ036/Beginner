#include"Thread.h"
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;


/**
 * Project Untitled
 */


#include "Thread.h"

/**
 * Thread implementation
 */

Thread::Thread(ThreadCallback &&cb)
    :_thid(0)
     ,_isRunning(false)
    ,_cb(std::move(cb))
{

}


Thread::~Thread() {

}

/**
 * @return void
 */
void Thread::start() {
    int ret = pthread_create(&_thid,nullptr,threadFunc,this);
    if(ret){
        perror("pthread_create");
        return;
    }

    _isRunning = true;
}

/**
 * @return void
 */
void Thread::stop() {
    if(_isRunning){
        cout << pthread_self() << endl;
        int ret = pthread_join(_thid,nullptr);
        if(ret){
            perror("pthread_join");
            return;
        }

        _isRunning = false;
    }
}

/**
 * @param arg 
 * @return void *
 */
void * Thread::threadFunc(void * arg ) {
    Thread *pth = static_cast<Thread *> (arg);
    if(pth){
        pth->_cb();
    }
    else{
        cout << "nullptr == pth" << endl;
    }

    pthread_exit(nullptr);
}

