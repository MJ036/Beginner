#include <iostream>
#include <math.h>
#include <unordered_set>


using std::cout;
using std::endl;
using std::unordered_set;

template<class T>
void display(const T &con){
    for(auto &elem : con){
        cout << elem << " ";
    }
    cout << endl;
}


class Point
{
public:
    Point(int ix = 0, int iy = 0)
        : _ix(ix)
          , _iy(iy)
    {}

    float getDistance() const
    {
        return hypot(_ix, _iy);
    }

    int getX() const
    {
        return _ix;
    }

    int getY() const
    {
        return _iy;
    }

    ~Point()
    {}

    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
private:
    int _ix;
    int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
    os << "(" << rhs._ix
        << ", " << rhs._iy
        << ")";

    return os;
}

namespace std{

template<>
    struct hash<Point>{
        size_t operator()(const Point &rhs) const{
            return ((rhs.getX() << 2)^(rhs.getY() << 2));
        }
    };// end of hash
}// end of namespace std

struct HashPoint{
    size_t operator()(const Point &rhs) const 
    {
        cout << "struct HashPoint" << endl;
        return ((rhs.getX() << 2) ^ (rhs.getY() << 5));
    }
};

bool operator==(const Point &lhs,const Point &rhs){
    return((lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY()));
}

namespace std{
template<>
    struct equal_to<Point>{
        bool operator()(const Point &lhs,const Point &rhs) const{
            return((lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY()));
        }
    };// end of equal
}// end of std

struct EqualToPoint
{
    bool operator()(const Point &lhs, const Point &rhs) const 
    {
        cout << "struct EqualToPoint" << endl;

        return ((lhs.getX() == rhs.getX()) &&(lhs.getY() == rhs.getY()));
    }
};

void test(){
    /* unordered_set<Point> number = { */ 
    unordered_set<Point, HashPoint> number = {
    /* unordered_set<Point,std::hash<Point>,EqualToPoint> number = { */
        Point(1, 2),
        Point(-1, 2),
        Point(1, 2),
        Point(3, 2),
        Point(1, 10),
        Point(1, -2),
    };
    display(number);
}


int main()
{
    test();
    return 0;
}

