#include <mai.h>
#include <iostream>
#include <workflow/WFFacilities.h>
static WFFacilities::WaitGroup gWaitGroup(2);

void handler(int signum){
    printf("signum = %d\n",signum);
    gWaitGroup.done();
}

int main()
{
    signal(SIGINT,handler);
    gWaitGroup.wait();
    return 0;
}

