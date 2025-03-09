/**
 * Project Untitled
 */

#include<pthread.h>

#ifndef _THREAD_H
#define _THREAD_H

class Thread {
public: 
    
Thread();
    
virtual ~Thread();
    
void start();
    
void stop();
private: 
    pthread_t _thid;
    bool _isRunning;
    
/**
 * @param arg
 */
static void * threadFunc(void * arg);
    
virtual void run() = 0;
};

#endif //_THREAD_H
