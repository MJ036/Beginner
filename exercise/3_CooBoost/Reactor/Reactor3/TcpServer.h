#ifndef __TCPSERVER_H__
#define __TCPSERVER_H__

#include "EventLoop.h"
#include "Acceptor.h"


class TcpServer
{
public:
    TcpServer(const string &,unsigned short);
    ~TcpServer();

    void start();
    void stop();
    void setAllCallback(TcpConnectionCallback &&,TcpConnectionCallback &&,TcpConnectionCallback &&);

private:
    Acceptor _acceptor;
    EventLoop _loop;

};

#endif
