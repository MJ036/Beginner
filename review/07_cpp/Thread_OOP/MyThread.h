/**
 * Project Untitled
 */


#ifndef _MYTHREAD_H
#define _MYTHREAD_H

#include "Thread.h"
#include <unistd.h>
#include <iostream>
using namespace std;


class MyThread: public Thread {
private: 
    
void run() override
{
    while(1){
        cout << "MyThread is runing " << endl;
        sleep(1);
    }
}
};

#endif //_MYTHREAD_H
