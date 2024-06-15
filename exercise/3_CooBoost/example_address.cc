#include <iostream>
using std::cout;
using std::endl;

class Example
{
};

void test()
{
    cout << "sizeof(Example) = " << sizeof(Example) << endl;
    Example ex;
    Example ex2;
    Example ex3;
    printf("&ex = %p\n", &ex);
    printf("&ex2 = %p\n", &ex2);
    printf("&ex3 = %p\n", &ex3);
}

int main()
{
    test();
    return 0;
}

