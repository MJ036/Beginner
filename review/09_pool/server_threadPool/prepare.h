int tcpInit(char *ip, char *port, int *pSockFd);
int epollCtor();
int epollAdd(int fd, int epfd);
