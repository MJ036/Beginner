#include "server.h"


int makeChild(processData_t *pProcessData, int processNum){
    pid_t pid;
    for(int i = 0; i < processNum; i++){
        int pipeFd[2];
        socketpair(AF_LOCAL,SOCK_STREAM,0,pipeFd);
        pid = fork();
        if(pid == 0){
            close(pipeFd[0]);
            handleEvent(pipeFd[1]);
        }
        close(pipeFd[1]);
        printf("pid = %d, pipeFd[0] = %d\n",pid,pipeFd[0]);
        pProcessData[i].pid = pid;
        pProcessData[i].status = FREE;
        pProcessData[i].pipeFd = pipeFd[0];
    }
    return 0;
}
void handleEvent(int pipeFd){
    int netFd;
    while(1){
        int exitFlag;
        recvFd(pipeFd,&netFd,&exitFlag);
        if(exitFlag == 1){
            puts("I am closing");
            exit(0);
        }
        transFile(netFd);
        sleep(10);
        close(netFd);
        pid_t pid = getpid();
        send(pipeFd,&pid,sizeof(pid_t),0);
    }
}
