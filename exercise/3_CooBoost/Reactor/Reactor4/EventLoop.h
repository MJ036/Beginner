#ifndef __EVENTLOOP_H__
#define __EVENTLOOP_H__

#include "MutexLock.h"
#include <vector>
#include <map>
#include <memory>
#include <functional>

using std::vector;
using std::map;
using std::shared_ptr;
using std::function;

class Acceptor;
class TcpConnection;

using TcpConnectionPtr = shared_ptr<TcpConnection>;
using TcpConnectionCallback = function<void(const TcpConnectionPtr &)>;
using Functor = function<void()>;

class EventLoop
{
public:
    EventLoop(Acceptor &acceptor);
    ~EventLoop();

    void loop();
    void unloop();

private:
    void waitEpollFd();
    void handleNewConnection();
    void handleMessage(int fd);
    int createEpollFd();
    void addEpollReadFd(int fd);
    void delEpollReadFd(int fd);

    
public:
    void setNewConnectionCallback(TcpConnectionCallback &&);
    void setMessageCallback(TcpConnectionCallback &&);
    void setCloseCallback(TcpConnectionCallback &&);

private:
    void handleRead();

    void doPendingFunctors();
    int createEventFd();
public:
    void wakeup();
    void runInloop(Functor &&cb);

private:
    int _epfd;
    vector<struct epoll_event> _evtList;
    bool _isLooping;
    Acceptor & _acceptor;
    map<int,TcpConnectionPtr> _conns;

    TcpConnectionCallback _onNewConnectionCb;
    TcpConnectionCallback _onMessageCb;
    TcpConnectionCallback _onCloseCb;

    int _evtfd;
    vector<Functor> _pendings;
    MutexLock _mutex;


};

#endif
