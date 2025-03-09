/**
 * Project Untitled
 */


#include "MyThread.h"
#include <any>
#include <memory>

/**
 * MyThread implementation
 */


/**
 * @return void
 */

void test(){
    MyThread mth;
    mth.start();
    mth.stop();
}

void test2(){
    unique_ptr<Thread> up(new MyThread());
    up->start();
    up->stop();
}

int main(){
    cout << "test2" << endl;
    test2();

}
