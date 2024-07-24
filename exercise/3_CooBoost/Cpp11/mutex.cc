#include <iostream>
#include <mutex>
#include <thread>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::lock_guard;
using std::unique_lock;

mutex mtx;
int gCnt = 0;

/* void threadFunc(){ */
/*     for(int idx = 0; idx < 10000000; ++idx){ */
/*         mtx.lock(); */
/*         gCnt++; */
/*         mtx.unlock(); */
/*     } */
/* } */

/* void threadFunc(){ */
/*     for(int idx = 0; idx < 10000000; ++idx){ */
/*         lock_guard<mutex> lg(mtx); */
/*         gCnt++; */
/*     } */
/* } */

void threadFunc(){
    for(int idx = 0; idx < 10000000; ++idx){
        unique_lock<mutex> ul(mtx);
        gCnt++;
    }
}



int main()
{
    std::cout << "Hello world" << std::endl;
    thread th1(threadFunc);
    thread th2(threadFunc);

    th1.join();
    th2.join();
    cout << "gCnt = " << gCnt << endl;
    return 0;
}

