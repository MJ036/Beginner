#include "Consumer.h"
#include "TaskQueue.h"
#include <unistd.h>
#include <iostream>

using std::endl;
using std::cout;

Consumer::Consumer(){
}

Consumer::~Consumer(){
}

void Consumer::consumer(TaskQueue &taskQue){
    int cnt = 20;
    while(cnt--)
    {
        int number = taskQue.pop();
        cout << "<<Consumer consume number = " << number << endl;
        sleep(1);
    }
}



