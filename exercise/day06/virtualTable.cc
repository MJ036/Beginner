#include <iostream>

using namespace std;

class Base
{
public:
    Base(long base = 0)
        :_base(base)
    {}

    virtual
        void f(){
            cout << "Base::f()" << endl;
        }

    virtual
        void g(){}

    virtual
        void h(){}

    ~Base(){}

private:
    long _base;
};

class Derived
:public Base
{
public:
    Derived(long base = 0,long derived = 0)
        :Base(base)
         ,_derived(derived)
    {}

    virtual
        void f()
        {
            cout << "Derived::f()" << endl;
        }

    virtual
        void g()
        {}

    virtual
        void h()
        {}


    ~Derived(){}

private:
    long _derived;
};

void test()
{
    Derived derived(10,20);
    printf("Derived的地址:%p\n",&derived);
    printf("虚表的地址:%p\n",(long*)*(long *)&derived);
    printf("第一个虚函数的地址:%p\n",(long *)*(long *)*(long*)&derived);

    cout << endl;

    typedef void (*Function)();
    Function f =(Function)*((long*)*(long*)&derived);
    f();
    printf("第一个虚函数的入口地址:%p\n",f);
}

int main()
{
    test();
    return 0;
}

