#include <string.h>
#include <iostream>

using namespace std;
//
//
//  右值和左值对比
//      
void test()
{
    int a = 10;
    int b = 20;
    int *pflag = &a;
    string s1 = "hello";
    string s2 = "world";

    const int &ref = a;
    const int & ref1 = 10;

    int &&rref = 10;

    &"string";

    &rref;
    &ref;

    &a;
    &b;
    &*pflag;
    &pflag;
    &s1;
    &s2;
    &(++a);
    &(a++);

}


int main()
{

    return 0;
}

