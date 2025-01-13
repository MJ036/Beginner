#include "func.h"

int main(int argc,char* argv[])
{
    unsigned short us = 0x1234;
    printf("%x\n",us);
    unsigned short us1 = htons(us);
    printf("%x\n",us1);
    printf("%x\n",ntohs(us1));


    return 0;
}

