#include <cmath>
#include <iostream>

using namespace std;

class Circle
{
public:
    Circle()
    {
        _radius = 0;
    }

    Circle(double radius)
    :_radius(radius)
    {}

    double getArea(){
        return M_PI*pow(_radius,2);
    }

    double getPerimeter(){
        return 2*M_PI*_radius;
    }

    void show(){
        cout << "radius: " << _radius << endl
            << "Area: " << getArea() << endl
            << "getPerimeter: " << getPerimeter() << endl;
    }

private:
    double _radius;
};


class Cylinder
:public Circle
{
public:
    Cylinder(double r,double h)
        :Circle(r)
         ,_height(h)
    {}

    double getVolume(){
        return getArea()*_height;
    }

    void showVolume(){
        cout << "Volume of Cylinder: " << getVolume() << endl;
    }
    
private:
    double _height;
};

void test(){
    Circle c1(2);
    c1.show();
}

void test2(){
    Cylinder cld(2,2);
    cld.show();
    cld.showVolume();
}

int main()
{
    test2();
    return 0;
}

