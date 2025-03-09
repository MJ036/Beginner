/**
 * Project Untitled
 */


#include "Thread.h"
#include <pthread.h>
#include <iostream>

using std::cout;
using std::endl;

/**
 * Thread implementation
 */


Thread::Thread()
:_thid(0)
    ,_isRunning(false)
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
void * Thread::threadFunc(void * arg) {
    Thread *pth = static_cast<Thread*> (arg);
    if(pth){
        pth->run();
    }else{
        cout << "pth == nullptr" << endl;
    }
    pthread_exit(nullptr);
}

