#include "func.h"

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
    
    int newfd = 0;
    char buf[64] = {0};
    fd_set rdset;
    fd_set needMonitorSet;
    FD_ZERO(&rdset);
    FD_ZERO(&needMonitorSet);
    FD_SET(STDIN_FILENO,&needMonitorSet);
    FD_SET(sfd,&needMonitorSet);

    while(1){
        memcpy(&rdset,&needMonitorSet,sizeof(fd_set));
        select(10,&rdset,NULL,NULL,NULL);
        if(FD_ISSET(STDIN_FILENO,&rdset)){
            memset(buf,0,sizeof(buf));
            int ret = read(STDIN_FILENO,buf,sizeof(buf));
            if(ret == 0){
                break;
            }
            send(newfd,buf,ret,0);
        }
        else if(newfd > 0 && FD_ISSET(newfd,&rdset)){
            memset(buf,0,sizeof(buf));
            ret = recv(newfd,buf,sizeof(buf),0);
            if(ret == 0){
                printf("byebye\n");
                close(newfd);
                FD_CLR(newfd,&needMonitorSet);
                continue;
            }
            printf("buf =%s\n",buf);
        }else if(FD_ISSET(sfd,&rdset)){
            printf("accept\n");
            struct sockaddr_in clientAddr;
            memset(&clientAddr,0,sizeof(clientAddr));
            socklen_t socklen = sizeof(clientAddr);
            newfd = accept(sfd,(struct sockaddr *)&clientAddr,&socklen);
            ERROR_CHECK(newfd,-1,"accept");
            FD_SET(newfd,&needMonitorSet);
            printf("sockLen =%d\n",socklen);
            printf("newfd=%d\n",newfd);
            printf("addr=%s,port=%d\n",inet_ntoa(clientAddr.sin_addr),ntohs(clientAddr.sin_port));
        }
    }
    close(sfd);
    close(newfd);
    return 0;
}

