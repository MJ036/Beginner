#include "func.h"
#include "threadpool.h"
#include "prepare.h"
#include "transFile.h"

#define EPOLL_ARR_SIZE 100

int exitPipe[2];
void sigHandler(int num){
    printf("sig:%d is coming.\n",num);
    int one = 1;
    write(exitPipe[1],&one,sizeof(one));
}
int main(int argc, char* argv[])
{
    // ./server ip port threadNum
    ARGS_CHECK(argc,4);
    pipe(exitPipe);
    pid_t pid = fork();
    if(pid > 0){
        printf("major process pid = %d\n",getpid());
        close(exitPipe[0]);
        signal(SIGUSR1,sigHandler);
        wait(NULL);
        close(exitPipe[1]);
        printf("\n parent process exit.\n");
        exit(0);
    }
    close(exitPipe[1]);

    int epfd = epollCtor();
    epollAdd(exitPipe[0],epfd);

    thread_pool_t threadpool;
    memset(&threadpool,0,sizeof(thread_pool_t));
    threadpoolInit(&threadpool,atoi(argv[3]));
    threadpoolStart(&threadpool);

    int listenfd;
    tcpInit(argv[1],argv[2],&listenfd);
    ERROR_CHECK(epfd,-1,"epollCtor");
    epollAdd(listenfd,epfd);
    struct epoll_event *preadyArr = (struct epoll_event*)calloc(EPOLL_ARR_SIZE,sizeof(struct epoll_event));
    while(1){
        int nready = epoll_wait(epfd,preadyArr,EPOLL_ARR_SIZE,-1);
        if(nready == -1 && errno == EINTR){
            continue;
        }else if(nready == -1){
            ERROR_CHECK(nready,-1,"epoll_wait");
        }else{
            for(int i = 0; i < nready; ++i){
                int fd = preadyArr[i].data.fd;
                if(fd == listenfd){
                    int peerfd = accept(listenfd,NULL,NULL);
                    taskEnque(&threadpool.que,peerfd);
                }else if(fd == exitPipe[0]){
                    //useless 2 lines
                    int howmany = 0;
                    read(exitPipe[0],&howmany,sizeof(howmany));

                    threadpoolStop(&threadpool);
                    threadpoolDestory(&threadpool);
                    close(listenfd);
                    close(epfd);
                    close(exitPipe[0]);
                    puts("child process exit");
                    exit(0);
                }
            }
        }
    }
    return 0;
}

