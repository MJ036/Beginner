#include <mai.h>
#include <iostream>
#include <vector>
#include <workflow/WFFacilities.h>
#include <workflow/MySQLUtil.h>
#include <workflow/MySQLMessage.h>
#include <workflow/MySQLResult.h>
using std::string;
using std::cerr;
using std::vector;


static WFFacilities::WaitGroup gWaitGroup(1);
void handle(int signum){
    printf("signum = %d\n",signum);
    gWaitGroup.done();
}

void timerCallback(WFTimerTask *timerTask){
    time_t now = time(NULL);
    cerr << "second = " << ctime(&now);
    WFTimerTask * nextTimerTask = 
        WFTaskFactory::create_timer_task(2,0,timerCallback);
    series_of(timerTask)->push_back(nextTimerTask);
}

int main()
{
    signal(SIGINT,handle);
    time_t now = time(NULL);
    WFTimerTask * timerTask = 
    WFTaskFactory::create_timer_task(2,0,timerCallback);
    cerr << "first = " << ctime(&now);
    timerTask->start();
    gWaitGroup.wait();

    return 0;
}

