#include "func.h"

int main(int argc,char* argv[])
{
    int ret = alarm(3);
    printf("first ret = %d\n", ret);
    sleep(2);
    ret = alarm(2);
    printf("first ret = %d\n", ret);

    return 0;
}

