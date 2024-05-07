#include <iostream>

using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

class Base
{
public:
    Base()
        :_base(0)
    {
        cout << "Base()" << endl;
    }

    Base (long base)
    :_base(base)
    {
        cout << "Base(long)" << endl;
    }

    ~Base()
    {
        cout << "~Base()"  << endl;
    }

private:
    long _base;
};

class Derived
:public Base
{
public:
    Derived()
        :Base(10)
         ,_tst()
         ,_derived(0)
    {
        cout << "Derived()" << endl;
    }
    

    Derived(long derived)
        :Base(derived)
         ,_derived(derived)
    {
        cout << "Derived(long)" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }

private:
    Test _tst;
    long _derived;
    
};

int main()
{
    Derived d;
    return 0;
}

