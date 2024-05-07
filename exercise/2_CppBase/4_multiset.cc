#include <math.h>
#include <iostream>
#include <set>
#include <vector>
#include <utility>

using std::cout;
using std::endl;
using std::multiset;
using std::vector;
using std::pair;

template <typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem << "  ";
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
    friend bool operator<(const Point &lhs, const Point &rhs);
    friend struct ComparePoint;
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

//运算符重载
bool operator<(const Point &lhs, const Point &rhs)
{
    cout << "bool operator<" << endl;
    if(lhs.getDistance() < rhs.getDistance())
    {
        return true;
    }
    else if(lhs.getDistance() == rhs.getDistance())
    {
        if(lhs._ix < rhs._ix)
        {
            return true;
        }
        else if(lhs._ix == rhs._ix)
        {
            if(lhs._iy < rhs._iy)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

//函数对象
struct ComparePoint
{
    bool operator()(const Point &lhs, const Point &rhs) const
    {
        cout << "struct ComparePoint" << endl;
        if(lhs.getDistance() < rhs.getDistance())
        {
            return true;
        }
        else if(lhs.getDistance() == rhs.getDistance())
        {
            if(lhs._ix < rhs._ix)
            {
                return true;
            }
            else if(lhs._ix == rhs._ix)
            {
                if(lhs._iy < rhs._iy)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};

//模板的特化
//命名空间的扩展
namespace std
{
//模板的特化（全特化）
template <>
struct less<Point>
{
    bool operator()(const Point &lhs, const Point &rhs) const
    {
        cout << "template <>" << endl;
        if(lhs.getDistance() < rhs.getDistance())
        {
            return true;
        }
        else if(lhs.getDistance() == rhs.getDistance())
        {
            if(lhs.getX() < rhs.getX())
            {
                return true;
            }
            else if(lhs.getX() == rhs.getX())
            {
                if(lhs.getY() < rhs.getY())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};

}
void test()
{
    /* multiset<Point> number = { */
    multiset<Point, ComparePoint> number = {
        Point(1, 2),
        Point(-1, 2),
        Point(1, 2),
        Point(3, 2),
        Point(1, -2),
        Point(4, -2),
    };
    display(number);
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

