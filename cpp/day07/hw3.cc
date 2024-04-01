#include <iostream>

using namespace std;

class Base
{
public:
    Base(int i)
    :_i(i)
    {}
friend    
    int operator+(const Base &lhs,const Base & rhs);

private:
    int _i;
};

int operator+(const Base &lhs,const Base & rhs){
    return -(lhs._i - rhs._i);
}

void test()
{
    int i = 2;
    int j = 7;

    Base x(i);
    Base y(j);
    cout << (x + y == j - i) << endl;
}

int main()
{
    test();
    return 0;
}

