#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>


class Thread
{
public:
    Thread();
    virtual ~Thread();

    void start();
    void stop();


private:
    //线程入口函数
    static void* threadFunc(void * arg);
    //抽象的任务（线程需要执行的任务）
    virtual void run() = 0;

private:
    pthread_t _thid;
    bool _isRuning;

};

#endif
