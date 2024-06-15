#include <iostream>
#include "Thread.h"
#include <unistd.h>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::bind;

class MyTask
{
public:
    void process(int x){
        while(1){
            cout << "MyTask is runing!!!" << endl;
            sleep(x);
        }
    }
    
};



void func(int x) 
{
    //...实现具体的逻辑
    while(1)
    {
        cout << "func is running!!!" << endl;
        sleep(x);
    }
}

void test(){
    MyTask task;
    function<void()> f = bind(&MyTask::process, &task,1);
    Thread mth(std::move(f));
    mth.start();
    mth.stop();
}

void test2(){
    MyTask task;
    unique_ptr<Thread> up (new Thread(std::bind(&MyTask::process,&task,1)));
    up->start();
    up->stop();

}

void test3(){
    unique_ptr<Thread> up(new Thread(std::bind(&func,1)));
    up->start();
    up->stop();
}

int main()
{
    std::cout << "Hello world" << std::endl;
    test3();
    return 0;
}

