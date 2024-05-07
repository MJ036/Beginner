#include <iostream>

using namespace std;

class Base
{
public:
    Base(long number = 0)
        :_number(number)
    {
        cout << "Base(long = 0)" << endl;
    }

    virtual
        void print()
        {
            cout << "Base::_number = " << _number << endl;
        }

    ~Base()
    {
        cout << "~Base()" << endl; 
    }

protected:
    long _number;
};

class Derived
:public Base
{
public:
    Derived(long number1 = 0,long number2 = 0)
        :Base(number1)
         ,_number(number2)
    {
        cout << "Derived(long = 0)" << endl;
    
    }
    virtual
    void print(int x)
    {
        cout << " x = " << x << endl;
        cout << "_number = " << _number << endl;
        cout << "Base::_number =" << Base::_number << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }

private:
    long _number;
};

int main()
{
    Derived derived(100,200);
    derived.print(1000000);

    return 0;
}

