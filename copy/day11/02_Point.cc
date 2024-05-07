#include <math.h>
#include <iostream>
#include <limits>

using namespace std;

class Point;

class Complex
{
    friend Point;
public:
    Complex(doubel dreal = 0.0,double dimage = 0.0)
        :_dreal(dreal)
         ,_dimage(dimage)
    {}

    Complex(const Complex &rhs)
        :_dreal(rhs._dreal)
         ,_dimage(rhs._dimage)
    {}

    Complex &operator+=(const Complex &rhs)
    {
        _dreal += rhs._dreal;
        _dimage += rhs._dimage;

        return *this;
    }

    Complex &operator++()
    {
        ++_dreal;
        ++_dimage;

        return *this;
    }

    Complex operator++(int)
    {
        Complex temp(*this);

        _dreal++;
        _dimage++;

        return temp;
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
        if(0 == _dreal && 0 == _dimage)
        {
            cout << 0 << endl;
        }
        else if(0 == _dreal)
        {
            cout << _dimage << "i" << endl;
        }
        else
        {
            cout << _dreal;
            if(_dimage > 0)
            {
                cout << " + " << _dimage << "i" << endl;
            }
            else if(_dimage < 0)
            {
                cout << " - " << -1 *_dimage << "i" << endl;
            }
            else
            {
                cout << endl;
            }
        }
    }

    ~Complex()
    {
        cout << "~Complex()" << endl; 
    }

    friend Complex operator+(const Complex &lhs,const Complex &rhs);

    friend ostream &operator<<

private:
    double _dreal;
    double _dimage;
};

