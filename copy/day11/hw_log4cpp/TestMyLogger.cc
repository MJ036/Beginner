#include "MyLogger.h"

#include <iostream>
#include <string>

using namespace std;

string func(const char *msg)
{
    string s1 = string(__FILE__) + string(" ")
                + string(__FUNCTION__) + string("  ")
                + string(std::to_string(__LINE__)) + msg;

    return s1;
}

void test()
{
    MyLogger *p1 = MyLogger::getInstance();

    logError("This is an error message");
}

void test2()
{
    cout << __FILE__ << "  " << __FUNCTION__ << "  " << __LINE__ << endl;
}

int main()
{
    test();
    test2();
    return 0;
}

