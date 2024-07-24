#include <iostream>
#include <thread>
#include <functional>

using std::cout;
using std::endl;
using std::thread;
using std::bind;
using std::function;

void threadFunc(int x){
    cout << "void threadFunc" << endl;
    cout << "x = " << x << endl;
    cout << "child thread id = " << std::this_thread::get_id() << endl;
}

class Example{
public:
    void operator()(int x){
        cout << "void threadFunc" << endl;
        cout << "x = " << x << endl;
        cout << "child thread id = " << std::this_thread::get_id() << endl;
    }
};


int main()
{
    cout << "main thread id  = " << std::this_thread::get_id() << endl;
    /* thread th(threadFunc,1); */

    /* typedef void(*pFunc)(int); */
    /* pFunc f = &threadFunc; */
    /* thread th(f,2); */

    /* typedef void(&pFunc)(int); */
    /* pFunc f = threadFunc; */
    /* thread th(f,3); */


    /* Example ex; */
    /* thread th(ex,4); */

    /* thread th([](int x){ */
    /*     cout << "x = " << x << endl; */
    /*     cout << "child thread id = " << std::this_thread::get_id() << endl; */
    /*           },5); */

    /* using namespace std::placeholders; */
    /* function<void(int)> f = bind(threadFunc,_1); */
    /* thread th(f,6); */

    thread th(bind(threadFunc,7));


    th.join();
    return 0;
}

