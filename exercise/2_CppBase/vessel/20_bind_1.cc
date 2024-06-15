#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::bind;

void func(int x1, int x2, int x3, const int &x4, int x5)
{
    cout << "x1 = " << x1 << endl
         << "x2 = " << x2 << endl
         << "x3 = " << x3 << endl
         << "x4 = " << x4 << endl
         << "x5 = " << x5 << endl;
}

void test(){
    int number = 100;
    using namespace std::placeholders;

    auto f = bind(func,10,_3,_1,std::cref(number),number);
    number = 200;
    f(20,30,40,50,60,70);

}

int main()
{
    test();
    std::cout << "Hello world" << std::endl;
    return 0;
}

