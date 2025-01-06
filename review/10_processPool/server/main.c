#include "head.h"
int exitPipe[2];

void handler(int sigNum){
    printf("signum = %d\n",sigNum);
    write(exitPipe[1],"1",1);
}

int main(int argc , char* argv[])
{
    // ./server ip port workNum;
    ARGS_CHECK(argc,4);

    //创建工作进程
    int workerNum = atoi(argv[3]);
    workerdata_t *workArr = (workerdata_t*)calloc(workerNum,sizeof(workerdata_t));
    makeWorker(workerNum,workArr);
    //注册退出信号、信号处理函数使用的管道
    pipe(exitPipe);
    signal(SIGUSR1,handler);

    //初始化tcp服务端
    int sockfd;
    tcpInit(argv[1],argv[2],&sockfd);
    //初始化epoll
    int epfd = epoll_create(1);
    epollAdd(epfd,sockfd);
    //监听每个子进程的pipe
    for(int i = 0; i < workerNum; ++i){
        epollAdd(epfd,workArr[i].pipesocketfd);
    }
    epollAdd(epfd,exitPipe[0]);

    while(1){
        struct epoll_event readySet[1024];
        int readyNum = epoll_wait(epfd,readySet,1024,-1);
        for(int i = 0; i < readyNum; ++i){
            if(readySet[i].data.fd == sockfd){
                int netfd = accept(sockfd,NULL,NULL);
                printf("1 client is connected!\n");
                for(int j = 0; j < workerNum; ++j){
                    if(workArr[j].status == FREE){
                        sendfd(workArr[j].pipesocketfd,netfd,0); //成功发送的netfd,交由工作进程关闭
                        workArr[j].status = BUSY;
                        break;
                    }
                }
                close(netfd); //没有空闲进程处理新的netfd时，关闭netfd
            }else if(readySet[i].data.fd == exitPipe[0]){ //收到退出信号，有序通知子进程退出
                for(int j = 0; j < workerNum; ++j){
                    puts("1");
                    int exitFlag = 1;
                    sendfd(workArr[j].pipesocketfd,0,exitFlag);
                    puts("kill 1 worker");
                }
                    for(int j = 0; j < workerNum; ++j ){
                        wait(NULL);
                    }
                    printf("All worker are killed !\n");
                    exit(0);
            }else{ // 收到子进程结束工作的通知
                int pipesocketfd = readySet[i].data.fd;
                for(int j = 0; j < workerNum; j++){
                    if(pipesocketfd == workArr[j].pipesocketfd){
                        pid_t pid;
                        recv(pipesocketfd,&pid,sizeof(pid),0);
                        printf("%d worker, pid = %d\n", j, pid);
                        workArr[j].status = FREE;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
