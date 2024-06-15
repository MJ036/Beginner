#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::bind;
using std::function;

int add(int x, int y)
{
    cout << "int add(int, int) " << endl;
    return x + y;
}

int multiply(int x, int y, int z)
{
    cout << "int multiply(int, int, int)" << endl;
    return x * y * z;
}

class Example
{
public:
    int add(int x, int y)
    {
        cout << "int Example::add(int, int)" << endl;
        return x + y;
    }

    int data = 250;//C++11
};

void test(){
    function<int()> f = bind(add,1,2);
    cout << "f() = " << f() << endl;

    function<int()> f2 = bind(multiply,3,4,5);
    cout << "f2() = " << f2() << endl;

    Example ex;
    function<int()> f3 = bind(&Example::add,&ex,10,30);
    cout << "f3() = " << f3() << endl;

    using namespace std::placeholders;
    function<int(int)> f4 = bind(add,10,_1);
    cout << "f4(40) = " << f4(40) << endl;

    function<int()> f5 = bind(&Example::data,&ex);
    cout << "f5() = " << f5() << endl;

}

void test2(){
    Example ex;
    function<int()> f = bind(&Example::add,&ex,10,30);
    cout << "f() = " << f() <<endl;
}

int main()
{
    test();
    std::cout << "Hello world" << std::endl;
    return 0;
}

