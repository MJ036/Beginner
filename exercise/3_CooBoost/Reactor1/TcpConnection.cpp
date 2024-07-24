/**
 * Project Reactor1
 */


#include "TcpConnection.h"

/**
 * TcpConnection implementation
 */


/**
 * @param fd
 */
 TcpConnection:: TcpConnection(int fd)
    :_socketIO(fd)
{

}

 TcpConnection::~TcpConnection() {

}

/**
 * @param msg
 * @return void
 */
void TcpConnection::send(const string & msg) {
    _socketIO.writen(msg.c_str(),msg.size());
}


/**
 * @return string
 */
string TcpConnection::recv() {
    char buff[65535] = {0};
    _socketIO.readLine(buff,sizeof(buff));
    return string(buff);
}
