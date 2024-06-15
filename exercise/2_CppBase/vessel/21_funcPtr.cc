#include <iostream>

using std::cout;
using std::endl;

int func2(int x, int y)
{
    return x + y;
}

int func3(int x, int y)
{
    return x * y;
}

int func4()
{
    return 400;
}

typedef int(*pFunc)(int,int);
// using pFunc = int();

void test(){
    pFunc f = &func2;
    cout << "f(1,2) = " << f(1,2) << endl; 

     f = func3;
    cout << "f(10,20) = " << f(10,20) << endl;

    /* f = func4; */
}

int main()
{
    test();
    std::cout << "Hello world" << std::endl;

    return 0;
}

