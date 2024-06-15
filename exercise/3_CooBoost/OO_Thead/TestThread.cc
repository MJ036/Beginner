#include <iostream>
#include "Thread.h"
#include <unistd.h>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

class MyThread
: public Thread
{
private:
    void run() override{
        while(1){
            cout << "MyThread is running" << endl;
            sleep(2);
        }
    }

};


void test(){
    MyThread mth;
    mth.start();
    mth.stop();
}

void test2(){
    unique_ptr<Thread> up (new MyThread());
    up->start();
    up->stop();

}

int main()
{
    std::cout << "Hello world" << std::endl;
    test2();
    return 0;
}

