#include "func.h"

typedef struct train_s{
    int dataLength;
    char buf[1000];
}train_t;

int recvn(int netFd, void* pstart, int len);
int recvFile(int netFd);
int recvFile_mmp(int netFd);


