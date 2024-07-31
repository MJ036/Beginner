#ifndef __TIMERFD_H__
#define __TIMERFD_H__

#include <functional>

using std::function;
using std::bind;

class TimerFd
{
    using TimerFdCallback = function<void()>;
public:
    TimerFd(TimerFdCallback &&cb, int initSec,int periodicSec);
    ~TimerFd();

    void start();
    void stop();

private:
    void handleRead();
    int createTimerFd();
    void setTimer(int initSec,int periodicSec);

private:
    int _tfd;
    TimerFdCallback _cb;
    bool _isStarted;
    int _initSec;
    int _periodicSec;

};

#endif
