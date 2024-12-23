#include "func.h"

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,1);
    for (int i = 0; i < 3; i++) {
        printf("a\n");
        fork();
        wait(NULL);
    }    

//  printf的a在缓冲区中，缓冲区状态会被子进程拷贝
//    for (int i = 0; i < 3; i++) {
//        printf("a");
//        fork();
//        wait(NULL);
    return 0;
}

