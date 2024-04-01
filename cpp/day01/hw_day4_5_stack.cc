#include <iostream>

using namespace std;

class Point
{
    Point(int x,int y)
        :_x(x)
         ,_y(y)
    {}

    Point(const Point &rhs) = delete;
    Point operator=(const Point & rhs) = delete;
    
public:
    static Point & getInstance()
    {
        static Point pt(1,2);
        return pt;
    }

private:
    int _x;
    int _y;
};

void test0()
{
    Point &  pt = Point::getInstance();
    Point &  pt2 = Point::getInstance();
    cout << &pt << endl;
    cout << &pt2 << endl;
}
