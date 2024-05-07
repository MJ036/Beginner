#include <iostream>

using namespace std;

class Base
{
public:
    Base()
        :_base()
    {
        cout << "Base()" << endl;
    }

    Base(long base)
        :_base(base)
    {
        cout << "Base(long)" << endl;
    }

    void show() const
    {
        cout << "Base::_base = " << _base << endl;
    }

    ~Base()
    {
        cout << "~Base()" << endl;
    }

private:
    long _base;

};

class Derived
:public Base
{
public:
    Derived(long base, long derived)
        :Base(base)
         ,_derived(derived)
    {
        cout << "Derived(long,long)" << endl;
    }

    void print() const
    {
        show();
        cout << "Derived::_derived = " << _derived << endl;
    }
    
    ~Derived()
    {
        cout << "~Derived()" << endl;
    }

private:
    long _derived;
};

void test()
{
    Base b1;
    Base b2;
    b1 = b2;

    Derived d1(11,22);
    Derived d2(33,44);
    d1 = d2;
}

void test2()
{
    cout << "sizeof(Base) = " << sizeof(Base) << endl;
    cout << "sizeof(Derived)" << sizeof(Derived) << endl;

    Base base(10);
    base.show();

    cout << endl;
    Derived derived(1111,3333);
    derived.print();

    cout << endl;

    cout << "派生类对象向基类对象转换" << endl;
    base = derived;
    base.show();
    cout << endl;
    Base &ref = derived;
    ref.show();

    cout << endl;

    Base *pbase = &derived;
    pbase->show();

    Base base2(1234);
    Derived *pderived2 = static_cast<Derived *>(&base2);

    Derived derived3(1000,2000);
    Base *pbase3 = &derived3;
    Derived *pderived3 = static_cast<Derived *>(pbase3);
}



int main()
{
    test2();
    return 0;
}

