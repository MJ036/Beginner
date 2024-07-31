#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>
#include <functional>

using std::function;


class Thread
{
    using ThreadCallback = function<void()>;
public:
    Thread(ThreadCallback &&cb);
    virtual ~Thread();

    void start();
    void stop();


private:
    //线程入口函数
    static void* threadFunc(void * arg);

private:
    pthread_t _thid;
    bool _isRuning;
    ThreadCallback _cb;

};

#endif
