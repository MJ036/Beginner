#include <iostream>

using namespace std;

class Base
{
    public:
    virtual void print() const = 0;
    virtual void  display() const = 0;
};

class Derived
:public Base
{
public:
     void print() const override
    {
        cout << "Derived::print()" << endl;
    }
};

class Derived2
:public Derived
{
public:
     void display() const override
    {
        cout << "Derived2::display()" << endl;
    }
};


int main()
{
    /* Base base; */
    /* Derived derived; */

    Derived2 derived2;
    derived2.print();

    Base *pbase = &derived2;
    Derived *pderived = &derived2;
    pbase->print();
    pderived->display();

    cout << endl;
    pderived->print();
    pderived->display();

    return 0;
}

