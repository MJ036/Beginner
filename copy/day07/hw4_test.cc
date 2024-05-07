#include "hw4.hh"
#include <string>
#include <iostream>


using std::cout;
using std::endl;
using std::string;

void test0(){
    LogError("The log is error messages");
    LogWarn("The log is warn message");
    Mylogger::getInstance()->debug(addPrefix("The log is debug message"));
    Mylogger::getInstance()->info(addPrefix("The log is info message"));
    Mylogger::destroy();
}

void test1(){
    cout << addPrefix("hello") << endl;
}

int main()
{
    int count = 100;
    while(count-- > 0){
        test0();
    }

    test1();
    return 0;
}

