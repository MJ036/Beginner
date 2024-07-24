#include "TimerFd.h"
#include <unistd.h>
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

class MyTask
{
public:
    void process()
    {
        cout << "MyTask is running" << endl;
    }
};

void test(){
    MyTask task;
    TimerFd tfd(bind(&MyTask::process,&task),1,5);
    thread th(&TimerFd::start,&tfd);

    sleep(30);

    tfd.stop();
    th.join();
}


int main(int argc, char *argv[])
{
    test();
    return 0;
}

