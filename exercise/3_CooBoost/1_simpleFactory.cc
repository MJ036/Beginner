#include <iostream>
#include <math.h>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;

class Figure
{
public:
    //纯虚函数
    virtual void display() const = 0;
    virtual double area() const = 0;

    virtual ~Figure(){}
};

class Rectangle
: public Figure
{
public:
    Rectangle(double length = 0, double width = 0)
    : _length(length)
    , _width(width)
    {
        cout << "Rectangle(double = 0, double = 0)" << endl;
    }

    void display() const override
    {
        cout << "Rectangle";
    }

    double area() const override
    {
        return _length * _width;
    }

    ~Rectangle()
    {
        cout << "~Rectangle()" << endl;
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
        cout << "Circle(double = 0)" << endl;
    }

    void display() const override
    {
        cout << "Circle";
    }

    double area() const override
    {
        return 3.14 * _radius *_radius;;
    }

    ~Circle()
    {
        cout << "~Circle()" << endl;
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
        cout << "Triangle(double = 0, double = 0, double = 0)" << endl;
    }

    void display() const override
    {
        cout << "Triangle";
    }

    double area() const override
    {
        //海伦公式
        double tmp = (_a + _b + _c)/2;

        return sqrt(tmp * (tmp - _a) * (tmp - _b) * (tmp - _c));
    }

    ~Triangle()
    {
        cout << "~Triangle()" << endl;
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

class Factory{
public:
    static Figure *create(const string &name){
        if(name == "rectangle")
        {
            //配置文件进行传递进来
            //txt、xml、yang
            //读配置文件
            //获取配置文件中的信息
            Rectangle *prec = new Rectangle(10, 20);

            return prec;
        }
        else if(name == "circle")
        {
            //配置文件进行传递进来
            //txt、xml、yang
            //读配置文件
            //获取配置文件中的信息
            Circle *pcir = new Circle(10);

            return pcir;
        }
        else if(name == "triangle")
        {
            //配置文件进行传递进来
            //txt、xml、yang
            //读配置文件
            //获取配置文件中的信息
            Triangle *ptri = new Triangle(3, 4, 5);

            return ptri;
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    unique_ptr<Figure> prec(Factory::create("rectangle"));
    unique_ptr<Figure> pcir(Factory::create("circle"));
    unique_ptr<Figure> ptri(Factory::create("triangle"));

    cout << endl;
    func(prec.get());
    func(pcir.get());
    func(ptri.get());
    cout << endl;

    return 0;
}

