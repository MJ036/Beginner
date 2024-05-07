#include <iostream>

using namespace std;

class A
{
public:
    A(long lx = 0)
        :_lx(lx)
    {
        cout << "A(long = 0)" << endl;
    }

    void setX(long lx)
    {
        _lx = lx;
    }

    void print() const
    {
        cout << "A::_lx = " << _lx << endl;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }

private:
    long _lx;
};

class B
:virtual public A
{

};

class C
:virtual public A
{

};

class D
:public B
,public C
{
public:
    D()
    {
        cout << "D()" << endl;
    }

    ~D()
    {
        cout << "~D()" << endl;
    }
};

int main()
{
    cout << "sizeof(A) = " << sizeof(A) << endl;
    cout << "sizeof(B) = " << sizeof(B) << endl;
    cout << "sizeof(C) = " << sizeof(C) << endl;
    cout << "sizeof(D) = " << sizeof(D) << endl;

    D d;
    d.B::setX(10);
    d.B::print();

    cout << endl;
    d.C::setX(20);
    d.C::print();

    cout << endl;
    d.setX(30);
    d.print();
    return 0;

}

