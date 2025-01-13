#include "head.h"
int makeWorker(int workerNum,workerdata_t *workArr){
    for(int i = 0; i < workerNum; ++i){
        int pipefd[2];
        socketpair(AF_LOCAL,SOCK_STREAM,0,pipefd);
        pid_t pid= fork();
        if(pid == 0){
            close(pipefd[1]);
            workLoop(pipefd[0]);
        }
        close(pipefd[0]);
        workArr[i].pid = getpid();
        workArr[i].status = FREE;
        workArr[i].pipesocketfd = pipefd[1];
        printf("i = %d, pid = %d, pipefd = %d\n",i,pid,pipefd[1]);
    }
    return 0;
}

int workLoop(int sockfd){
    while(1){
        int netfd;
        int exitFlag;
        recvfd(sockfd,&netfd,&exitFlag);
        if(exitFlag == 1){
            printf("I am going to exit!\n");
            exit(0);
        }
        transFile(netfd);
        close(netfd);
        pid_t pid = getpid();
        send(sockfd,&pid,sizeof(pid),0);

    }
}
