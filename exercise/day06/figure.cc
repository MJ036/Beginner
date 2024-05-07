#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

//抽象类作为接口使用的例子
//可以实现多态
//
//面向对象的设计原则：开闭原则
//对扩展开放，对修改关闭
class Figure
{
public:
    virtual
    void display() = 0;
    virtual 
    double area() = 0;
};

class Rectangle
: public Figure
{
public:
    Rectangle(double length = 0, double width = 0)
    : _length(length)
    , _width(width)
    {

    }

    void display() override
    {
        cout << "Rectangle";
    }

    double area() override
    {
        return _length * _width;
    }
private:
    double _length;
    double _width;
};

class Circle
: public Figure
{
public:
    Circle(double radius = 0)
    : _radius(radius)
    {

    }

    void display() override
    {
        cout << "Circle";
    }

    double area() override
    {
        return 3.14 * _radius *_radius;;
    }
private:
    double _radius;
};

class Triangle
: public Figure
{
public:
    Triangle(double a = 0, double b = 0, double c = 0)
    : _a(a)
    , _b(b)
    , _c(c)
    {

    }

    void display() override
    {
        cout << "Triangle";
    }

    double area() override
    {
        double tmp = (_a + _b + _c)/2;

        return sqrt(tmp * (tmp - _a) * (tmp - _b) * (tmp - _c));
    }
private:
    double _a;
    double _b;
    double _c;
};

void func(Figure *pfig)
{
    pfig->display();
    cout << "的面积 : " << pfig->area() << endl;
}

int main()
{
    Rectangle rectangle(10,20);
    Circle circle(10);
    Triangle triangel(3,4,5);

    func(&rectangle);
    func(&circle);
    func(&triangel);
    return 0;
}
