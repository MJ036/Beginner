#include <iostream>

using std::cout;
using std::endl;

namespace MySpace
{
    extern void swap(int *a,int *b);
}

int main()
{
    using MySpace::swap;
    int a=1,b=2;
    swap(&a,&b);
    cout << "a = " << a
        << " , " << "b = " << b << endl;
    return 0;
}

