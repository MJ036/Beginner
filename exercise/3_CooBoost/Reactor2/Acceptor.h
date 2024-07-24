/**
 * Project Reactor1
 */


#ifndef _ACCEPTOR_H
#define _ACCEPTOR_H

#include "Socket.h"
#include "InetAddress.h"
#include<string>

using std::string;

class Acceptor {
public: 

    Acceptor(const string & ip, unsigned short port);
    ~Acceptor();
    void ready();

private:
    void setReuseAddr();
    void setReusePort();
    void bind();
    void listen();

public:
    int accept();
    int fd() const;
    
private: 
    Socket _sock;
    InetAddress _addr;
};

#endif //_ACCEPTOR_H
