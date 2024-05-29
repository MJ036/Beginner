#include <iostream>
#include <cmath>

using namespace std;

class Point;

//只有前向声明，Point类没有实现，故无法使用这个类的对象，无法创建
//class Line{
//public:
//    float distance(const Point &lhs, const Point &rhs){
//        return sqrt((lhs._ix - rhs._ix)*(lhs._iy - rhs._iy))
//    }
//};

class Line{
public:
    float distance(const Point &lhs,const Point &rhs);
};


class Point{
public:
    Point(int x, int y):_ix(x),_iy(y){}
    friend float Line::distance(const Point &lhs,const Point &rhs);
private:
    int _ix;
    int _iy;
};

float Line::distance(const Point &lhs,const Point &rhs){
    return sqrt(pow(lhs._ix - rhs._ix,2) + pow(lhs._iy - rhs._iy,2));
}

void test0(){
    Point pt(0,0);
    Point pt1(3,4);
    Line l;
    cout << l.distance(pt,pt1) << endl;
}

int main()
{
    test0();
    return 0;
}

