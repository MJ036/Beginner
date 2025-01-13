#include "func.h"
#include "setNonblock.h"
//这个服务器适用于单一的1v1的客户端连接

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    int sfd = socket(AF_INET,SOCK_STREAM,0);
    ERROR_CHECK(sfd,-1,"socket");
    struct sockaddr_in serAddr;
    memset(&serAddr,0,sizeof(serAddr));
    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr(argv[1]);
    serAddr.sin_port = htons(atoi(argv[2]));

    int ret;

    int reuse = 1;
     ret = setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
    ERROR_CHECK(ret,-1,"setsockopt");

    ret = bind(sfd,(struct sockaddr *)&serAddr,sizeof(serAddr));
    ERROR_CHECK(ret,-1,"bind");
    ret = listen(sfd,10);
    ERROR_CHECK(ret,-1,"listen");
    
    int epfd = epoll_create(1); 
    ERROR_CHECK(epfd,-1,"epoll");
    struct epoll_event event,evs[2];
    memset(&event,0,sizeof(event));
    event.data.fd = STDIN_FILENO;
    event.events = EPOLLIN;
    ret = epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl");
    event.data.fd = sfd;
    ret = epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl");

    int readyNum = 0;
    char buf[4] = {0};
    int newfd = 0;
    time_t lastTime,nowTime;
    lastTime = nowTime = time(NULL);
    int isCliLogin = 0;

    while(1){
        readyNum = epoll_wait(epfd,evs,2,1000);
        printf("readyNum = %d\n",readyNum);
        if(readyNum == 0 && isCliLogin == 1){
            nowTime = time(NULL);
            if(nowTime - lastTime > 5){
                printf("close\n");
                close(newfd);
                isCliLogin = 0;
            }
        }
        for(int i = 0; i < readyNum; ++i){
            lastTime = time(NULL);
            printf("readyNum=%d fd=%d\n",readyNum,evs[i].data.fd);
            if(newfd > 0 && evs[i].data.fd == STDIN_FILENO){
                memset(buf,0,sizeof(buf));
                ret = read(STDIN_FILENO,buf,sizeof(buf));
                send(newfd,buf,ret,0);
            }else if(newfd > 0 && evs[i].data.fd == newfd){
                while(1){
                    memset(buf,0,sizeof(buf));
                    ret = recv(newfd,buf,sizeof(buf),0);
                    if(ret == 0){
                        printf("client say :bye\n");
                        close(newfd);
                        isCliLogin = 0;
                        continue;
                    }else if(ret == -1){
                        break;
                    }
                    printf("buf=%s\n",buf);
                }
            }else if(evs[i].data.fd == sfd){
                newfd = accept(sfd,NULL,NULL);
                ERROR_CHECK(newfd,-1,"accept");
                printf("newfd=%d\n",newfd);
                setNonblock(newfd);
                isCliLogin = 1;
                event.data.fd = newfd;
                event.events = EPOLLIN | EPOLLET;
                ret = epoll_ctl(epfd,EPOLL_CTL_ADD,newfd,&event);
                ERROR_CHECK(ret,-1,"epoll_ctl");
            }
        }
    }
    close(sfd);
    close(epfd);
    return 0;
}

