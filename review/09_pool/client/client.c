#include "clientFunc.h"

int main(int argc, char* argv[])
{
    // ./client ip port
    ARGS_CHECK(argc,3);
    int sockFd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    bzero(&addr,sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));
    int ret = connect(sockFd,(struct sockaddr*)&addr,sizeof(struct sockaddr_in));
    ERROR_CHECK(ret,-1,"connect");

    struct timeval before_trans_time;
    struct timeval after_trans_time;

    gettimeofday(&before_trans_time,NULL);
    recvFile(sockFd);
    gettimeofday(&after_trans_time,NULL);

    printf("传输文件耗时：%ld us\n",1000000*(after_trans_time.tv_sec - before_trans_time.tv_sec) + after_trans_time.tv_usec - before_trans_time.tv_usec);
    close(sockFd);
    return 0;
}


