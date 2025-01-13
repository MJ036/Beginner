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
    int ret = connect(sfd,(struct sockaddr *)&serAddr,sizeof(serAddr));
    ERROR_CHECK(ret,-1,"connect");
    

    char buf[64] = {0};
    fd_set rdset;
    while(1){
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(sfd,&rdset);
        select(sfd+1,&rdset,NULL,NULL,NULL);
        if(FD_ISSET(STDIN_FILENO,&rdset)){
            memset(buf,0,sizeof(buf));
            int ret = read(STDIN_FILENO,buf,sizeof(buf));
            if(ret == 0){
                break;
            }
            send(sfd,buf,ret,0);
        }
        else if(FD_ISSET(sfd,&rdset)){
            memset(buf,0,sizeof(buf));
            ret = recv(sfd,buf,sizeof(buf),0);
            if(ret == 0){
                break;
            }
            printf("buf =%s\n",buf);
        }
    }
    close(sfd);
    return 0;
}

