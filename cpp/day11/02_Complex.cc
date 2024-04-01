#include <iostream>
#include <limits>

using std::cout;
using std::endl;

class Complex
{
public:
    Complex(double dreal = 0.0, double dimage = 0.0)
    : _dreal(dreal)
    , _dimage(dimage)
    {
        cout << "Complex(double = 0.0, double = 0.0)" << endl;
    }
#if 0
    Complex(const Complex &rhs)
    : _dreal(rhs._dreal)
    , _dimage(rhs._dimage)
    {
        cout << "Complex(const Complex &)" << endl;
    }
#endif
    //c3 += c1;
    //复合赋值运算符的重载，以成员函数的形式(对于对象本身发生改变的，以成员
    //函数的形式进行重载)
    Complex &operator+=(const Complex &rhs)
    {
        cout << "Complex &operator+=(const Complex &)" << endl;
        _dreal += rhs._dreal;
        _dimage += rhs._dimage;

        return *this;
    }

    //对于前置++进行重载
    //Q：前置++比后置++效率高
    //A:前置++没有拷贝，后置++有拷贝操作；前置++是左值，后置++是右值
    Complex &operator++()
    {
        cout << "Complex operator++()" << endl;
        ++_dreal;
        ++_dimage;

        return *this;
    }

    /* (c3++); */
    Complex operator++(int)//此处的int只是做一个标识，不表示传参
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
        /* cout << _dreal << " + " << _dimage << "i" << endl; */
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
            if(_dimage > 0)//(1, 2)
            {
                cout << " + " << _dimage << "i" << endl;
            }
            else if(_dimage < 0)//1 - 2i (1, -2)
            {
                cout << " - " << -1 *_dimage  << "i" << endl;
            }
            else//(1, 0)
            {
                cout << endl;
            }
        }
    }

    ~Complex()
    {
        cout << "~Complex()" << endl;
    }
    
    friend Complex operator+(const Complex &lhs, const Complex &rhs);

    //cout << c1
    //输出流运算符不能以成员函数的形式进行重载，因为对于输出流运算符而言，
    //第一个参数是流对象，而将输出流运算符作为成员函数进行重载，流对象就
    //成为了第二个参数，此时与运算符重载的规则，“不能改变操作数的位置”，
    //所以输出流运算符不能以成员函数进行重载
    friend std::ostream &operator<<(std::ostream &os, const Complex &rhs);
    friend std::istream &operator>>(std::istream &is, Complex &rhs);


private:
    double _dreal;
    double _dimage;
};

Complex operator+(const Complex &lhs, const Complex &rhs)
{
    cout << "Complex operator+(const Complex &, const Complex &)" << endl;

    return Complex(lhs._dreal + rhs._dreal, lhs._dimage + rhs._dimage);
}

std::ostream &operator<<(std::ostream &os, const Complex &rhs)
{
    cout << "friend std::ostream &operator<<(std::ostream &, const Complex &)" << endl;

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
        if(rhs._dimage > 0)//(1, 2)
        {
            os << " + " << rhs._dimage << "i" << endl;
        }
        else if(rhs._dimage < 0)//1 - 2i (1, -2)
        {
            os << " - " << -1 * rhs._dimage  << "i" << endl;
        }
        else//(1, 0)
        {
            os << endl;
        }
    }

    return os;
}

void readDouble(std::istream &is, double &number)
{
    //真值表达式
    //逗号表达式
    while(is >> number, !is.eof())
    {
        if(is.bad())
        {
            std::cerr << "The stream is bad" << endl;
            return;
        }
        else if(is.fail())
        {
            //重置流的状态
            is.clear();
            //清空缓冲区
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "pls input valid double data" << endl;
        }
        else
        {
            cout << "number = " << number << endl;
            break;//跳出循环
        }

    }
}

std::istream &operator>>(std::istream &is, Complex &rhs)
{
    cout << "std::istream &operator>>(std::istream &, Complex &)" << endl;
    /* is >> rhs._dreal >> rhs._dimage; */
    readDouble(is, rhs._dreal);
    readDouble(is, rhs._dimage);
    return is;
}

void test()
{
    Complex c1(1, 2);
    cout << "c1 = " << c1 << endl;

    cout << endl;
    Complex c2;
    std::cin >> c2;
    cout << "c2 = " << c2 << endl;
}

int main(int argc, char **argv)
{
    test();
    return 0;
}


