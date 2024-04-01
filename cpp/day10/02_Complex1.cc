#include <iostream>

using namespace std;

class Complex
{
public:
    Complex(double dreal = 0.0,double dimage = 0.0)
        :_dreal(dreal)
         ,_dimage(dimage)
    {
        cout << "Complex(double = 0.0,double = 0.0)" << endl;
    }
    
    Complex(const Complex & rhs)
        :_dreal(rhs._dreal)
         ,_dimage(rhs._dimage)
    {
        cout << "Complex(const Complex &)" << endl;
    }

    double getReal() const
    {
        return _dreal;
    }

    double getImage() const
    {
        return _dimage;
    }

    void print() const
    {
        cout << _dreal << " + " << _dimage << "i" << endl;
    }

    ~Complex()
    {
        cout << "~Complex" << endl;
    }

private:
    double _dreal;
    double _dimage;
};

Complex operator+(const Complex &lhs,const Complex &rhs)
{
    cout << "Complex operator+(const Complex &,const Complex &)" << endl;
    return Complex(lhs.getReal() + rhs.getReal(),
                   lhs.getImage() + rhs.getImage());
}

void  test()
{
    int a = 10;
    int b = 20;
    int c = a + b;

    Complex c1(1,2);
    cout << "c1 = ";
    c1.print();
    
    cout << endl;
    Complex c2(3,4);
    cout << "c2 = ";
    c2.print();

    cout << endl;
    Complex c3 = c1 + c2;
    cout << "c3 = ";
    c3.print();
    cout << endl;
}

int main()
{   
    test();

    return 0;
}

