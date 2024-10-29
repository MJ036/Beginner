#include <iostream>
#include <limits>

using namespace std;

class Complex
{
public:
    Complex(double dreal = 0.0,double dimage = 0.0)
        :_dreal(dreal)
         ,_dimage(dimage)
    {
        cout << "Complex(double = 0.0, double = 0.0)" << endl;
    }

    Complex(const Complex &rhs)
        :_dreal(rhs._dreal)
         ,_dimage(rhs._dimage)
    {
        cout << "Complex(const Complex &)" << endl;
    }

    Complex &operator+=(const Complex &rhs)
    {
        cout << "Complex &operator+=(const Complex &)" << endl;
        _dreal += rhs._dreal;
        _dimage += rhs._dimage;
        return *this;
    }

    Complex &operator++()
    {
        cout << "Complex operator++()" << endl;
        ++_dreal;
        ++_dimage;
        return *this;
    }

    Complex operator++(int)
    {
        Complex tmp(*this);

        _dreal++;
        _dimage++;

        return tmp;
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
                cout << " - " << _dimage << "i" << endl;
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

    friend std::ostream &operator<<(std::ostream &os,const Complex &rhs);
    friend std::istream &operator>>(std::istream &is,Complex &rhs);
    

private:
    double _dreal;
    double _dimage;
};



std::ostream &operator<<(std::ostream &os,const Complex &rhs)
{
    cout << "frined std::ostream &operator<<(std::ostream &,const Complex &)" << endl;
    if(0 == rhs._dreal && 0 == rhs._dimage)
    {
        os << 0 << endl;
    }
    else if(0 == rhs._dreal)
    {
        os << rhs._dimage << "i" << endl;
    }
    else
    {
        os << rhs._dreal;
        if(rhs._dimage > 0)
        {
            os << " + " << rhs._dimage << "i" << endl;
        }
        else if(rhs._dimage < 0)
        {
            os << " - " << rhs._dimage << "i" << endl;
        }
        else
        {
            os << endl;
        }
    }
    return os;
}

void readDouble(std::istream &is,double &number)
{
    while(is >> number,!is.eof())
    {
        if(is.bad())
        {
            std::cerr << "The stream is bad" << endl;
            return;
        }
        else if(is.fail())
        {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "pls input valid double data" << endl;
        }
        else
        {
            cout << "number = " << number << endl;
            break;
        }
    }
}

std::istream &operator>>(std::istream &is,Complex &rhs)
{
    cout << "std::istream &operator>>(std::istream &,Complex &)" << endl;
    readDouble(is,rhs._dreal);
    readDouble(is,rhs._dimage);
    return is;
}

void test3()
{
    Complex c1(1,2);
    cout << "c1 = " << c1 << endl;
        
    cout << endl;
    Complex c2;
    std::cin >> c2;
    cout << "c2 = " << c2 << endl;
}

int main()
{
    test3();
    return 0;
}

