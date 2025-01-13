#include "func.h"
#include "server.h"

int sendFd(int pipeFd, int fdToSend,int exitFlag){
    struct msghdr hdr;
    bzero(&hdr,sizeof(struct msghdr));

    struct iovec iov[1];
    iov[0].iov_base = &exitFlag;
    iov[0].iov_len = sizeof(int);
    hdr.msg_iov = iov;
    hdr.msg_iovlen = 1;

    struct cmsghdr *pcmsghdr = (struct cmsghdr*)calloc(1,sizeof(struct cmsghdr));
    pcmsghdr->cmsg_len = CMSG_LEN(sizeof(int));
    pcmsghdr->cmsg_level = SOL_SOCKET;
    pcmsghdr->cmsg_type = SCM_RIGHTS; //SCM -> socket-level control message
    *(int*)CMSG_DATA(pcmsghdr) = fdToSend;

    hdr.msg_control = pcmsghdr;
    hdr.msg_controllen = CMSG_LEN(sizeof(int));

    int ret = sendmsg(pipeFd,&hdr,0);
    ERROR_CHECK(ret,-1,"sendmsg");
    return 0;
}

int recvFd(int pipeFd,int *pFd, int *exitFlag){
    struct msghdr hdr;
    bzero(&hdr,sizeof(struct msghdr));

    struct iovec iov[1];
    iov[0].iov_base = exitFlag;
    iov[0].iov_len = sizeof(int);
    hdr.msg_iov = iov;
    hdr.msg_iovlen = 1;

    struct cmsghdr *pcmsghdr = (struct cmsghdr*)calloc(1,sizeof(struct cmsghdr));
    pcmsghdr->cmsg_len = CMSG_LEN(sizeof(int));
    pcmsghdr->cmsg_level = SOL_SOCKET;
    pcmsghdr->cmsg_type = SCM_RIGHTS; //SCM -> socket-level control message

    hdr.msg_control = pcmsghdr;
    hdr.msg_controllen = CMSG_LEN(sizeof(int));

    int ret = recvmsg(pipeFd,&hdr,0);
    ERROR_CHECK(ret,-1,"recvmsg");
    *pFd = *(int *)CMSG_DATA(pcmsghdr);
    return 0;
}




