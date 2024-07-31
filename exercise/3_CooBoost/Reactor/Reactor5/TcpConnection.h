#ifndef _TCPCONNECTION_H
#define _TCPCONNECTION_H

#include "Socket.h"
#include "SocketIO.h"
#include "InetAddress.h"
#include "EventLoop.h"

#include <memory>
#include <functional>

using std::shared_ptr;
using std::function;
class TcpConnection;

using TcpConnectionPtr = shared_ptr<TcpConnection>;
using TcpConnectionCallback = function<void(const TcpConnectionPtr &)>;


class TcpConnection 
:public std::enable_shared_from_this<TcpConnection>
{
public: 
    explicit TcpConnection(int fd,EventLoop *loop);
    ~TcpConnection();
    void send(const string & msg);
    void sendInLoop(const string &msg);

    string receive();
    bool isClosed() const;

    //调试用到的函数
    string toString();

    void setNewConnectionCallback(const TcpConnectionCallback &);
    void setMessageCallback(const TcpConnectionCallback &);
    void setCloseCallback(const TcpConnectionCallback &);

    void handleNewConnectionCallback();
    void handleMessageCallback();
    void handleCloseCallback();

private:
    InetAddress getLocalAddr();
    InetAddress getPeerAddr();

private: 
    EventLoop *_loop;
    SocketIO _socketIO;

    //调试用
    Socket _sock;
    InetAddress _localAddr;
    InetAddress _peerAddr;

    TcpConnectionCallback _onNewConnectionCb;
    TcpConnectionCallback _onMessageCb;
    TcpConnectionCallback _onCloseCb;
};

#endif //_TCPCONNECTION_H
