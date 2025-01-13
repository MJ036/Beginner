#include "func.h"
#include "setNonblock.h"
int setNonblock(int fd){
    int ret = 0, status = 0;
    status = fcntl(fd,F_GETFL);
    status |= O_NONBLOCK;
    ret = fcntl(fd,F_SETFL,status);
    ERROR_CHECK(ret,-1,"fcntl");
    return 0;
}

