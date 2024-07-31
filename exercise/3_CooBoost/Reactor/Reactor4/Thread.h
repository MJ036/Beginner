/**
 * Project Untitled
 */


#ifndef _THREAD_H
#define _THREAD_H
#include <pthread.h>
#include <functional>

using std::function;

class Thread {
    using ThreadCallback = function<void()>;
public: 

    Thread(ThreadCallback &&);
     ~Thread();

    void start();

    void stop();
private: 
    pthread_t _thid;
    bool _isRunning;
    ThreadCallback _cb;

    /**
     * @param arg
     */
    static void * threadFunc(void * arg );

};

#endif //_THREAD_H
