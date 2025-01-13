#include "func.h"
#include "server.h"

int pipeFd[2];
void sigFunc(int signum){
    printf("signum = %d\n",signum);
    write(pipeFd[1],"1",1);
}

int main(int argc, char* argv[])
{
    // ./server ip port workerNum
    ARGS_CHECK(argc,4);
    printf("father pid = %d\n",getpid());
    int workerNum = atoi(argv[3]);
    processData_t *workerList = (processData_t*)calloc(workerNum,sizeof(processData_t));
    makeChild(workerList,workerNum);
    signal(SIGUSR1,sigFunc);

    int sockFd;
    tcpInit(argv[1],argv[2],&sockFd);
    int epfd = epollCtor();
    epollAdd(sockFd,epfd);

    pipe(pipeFd);
    epollAdd(pipeFd[0],epfd);

    for(int i = 0; i < workerNum; i++){
        epollAdd(workerList[i].pipeFd,epfd);
    }
    int listenSize = workerNum + 1;
    struct epoll_event *readyList = (struct epoll_event*)calloc(listenSize,sizeof(struct epoll_event));
    while(1){
        int readyNum = epoll_wait(epfd,readyList,listenSize,-1);
        for(int i = 0; i < readyNum; i++){
            if(readyList[i].data.fd == sockFd){
                puts("accept ready");
                int netFd = accept(sockFd,NULL,NULL);
                for(int j = 0; j < workerNum; j++){
                    if(workerList[j].status == FREE){
                        printf("No. %d worker gets his job, pid = %d\n",j,workerList[i].pid);
                        sendFd(workerList[j].pipeFd,netFd,0);
                        workerList[j].status = BUSY;
                        break;
                    }
                }
            }else if(readyList[i].data.fd == pipeFd[0]){
                for(int j = 0; j < workerNum; ++j){
                    puts("set signal to worker!");
                    sendFd(workerList[j].pipeFd,0,1);
                }
                for(int j = 0; j < workerNum; ++j){
                    wait(NULL);
                }
                puts("Parent process exit!\n");
                exit(0);
            }else{
                puts("One worker finish his task !");
                int j;
                for(j = 0; j < workerNum; ++j){
                    if(readyList[i].data.fd == workerList[j].pipeFd){
                        pid_t pid;
                        int ret = recv(workerList[i].pipeFd,&pid,sizeof(pid_t),0);
                        if(ret == -1){
                            perror("recv");
                            break;
                        }
                        printf("No. %d worker finish, pid = %d\n",j,pid);
                        workerList[j].status = FREE;
                        break;
                    }
                }
            }
        }
    }
}

