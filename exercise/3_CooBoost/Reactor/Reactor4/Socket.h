/**
 * Project Reactor1
 */


#ifndef _SOCKET_H
#define _SOCKET_H

class Socket {
public: 

    Socket();
    explicit Socket(int fd);
    ~Socket();
    int fd() const ;

private: 
    int _fd;
};

#endif //_SOCKET_H
