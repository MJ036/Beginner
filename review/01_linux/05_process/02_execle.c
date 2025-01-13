#include "func.h"

int main(int argc,char* argv[])
{
    char *const envp[] = {"PATH=/usr/lib",NULL};
    execle("./01_showPath","01_showPath",NULL,envp);

    return 0;
}

