/**
 * Project Reactor1
 */


#ifndef _TCPCONNECTION_H
#define _TCPCONNECTION_H

#include "Socket.h"
#include "SocketIO.h"
#include "InetAddress.h"

class TcpConnection {
public: 
    
/**
 * @param fd
 */
explicit TcpConnection(int fd);
    
~TcpConnection();
    
/**
 * @param msg
 */
void send(const string & msg);
    
string recv();

private: 
    SocketIO _socketIO;
};

#endif //_TCPCONNECTION_H
