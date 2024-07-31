#include <mai.h>
#include <string>
#include <iostream>
#include <vector>
#include <workflow/WFFacilities.h>
#include <workflow/MySQLUtil.h>
#include <workflow/MySQLMessage.h>
#include <workflow/MySQLResult.h>
using std::vector;
using std::string;
using std::cerr;
using namespace std;

static WFFacilities::WaitGroup gWaitGroup(1);

void handler(int signum){
    printf("signum = %d\n",signum);
    gWaitGroup.done();
}

//回调函数
void timerCallback(WFTimerTask *timerTask){
    time_t now = time(NULL);
    cerr << "second = " << ctime(&now);
//新建任务
    WFTimerTask * nextTimerTask = 
        WFTaskFactory::create_timer_task(2,0,timerCallback);
//把新建任务添加到序列
    series_of(timerTask)->push_back(nextTimerTask);
}


int main()
{
    signal(SIGINT,handler);
    time_t now = time(NULL);
    WFTimerTask *timerTask = 
        WFTaskFactory::create_timer_task(2,0,timerCallback);
    cerr << "first = " << ctime(&now);
    timerTask->start();
    gWaitGroup.wait();

    return 0;
}

