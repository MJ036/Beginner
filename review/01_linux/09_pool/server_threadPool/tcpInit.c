#include "func.h"
#include "prepare.h"

int tcpInit(char *ip, char *port, int *pSockFd){
    *pSockFd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = (htons(atoi(port)));
    int reuse = 1;
    int ret = setsockopt(*pSockFd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
    ERROR_CHECK(ret, -1 ,"setsockopt");
    ret = bind(*pSockFd,(struct sockaddr*)&addr,sizeof(struct sockaddr_in));
    ERROR_CHECK(ret,-1,"bind");
    listen(*pSockFd,10);
    return 0;
}
