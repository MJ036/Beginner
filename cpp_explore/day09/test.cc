#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }

    void print() const
    {
        cout << "(" << _ix 
             << ", " << _iy
             << ")";
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }

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

//模板相关的概念
template <typename T>
class RAII
{
public:
    //在构造函数中初始化资源
    RAII(T *data)
    : _data(data)
    {
        cout << "RAII(T *)" << endl;
    }

    //在析构函数中释放资源
    ~RAII()
    {
        cout << "~RAII()" << endl;
        if(_data)
        {
            delete _data;
            _data = nullptr;
        }
    }

    //提供若干访问资源的方法
    T *operator->()
    {
        return _data;
    }

    T &operator*()
    {
        return *_data;
    }

    T *get()
    {
        return _data;
    }

    void reset(T *data)
    {
        if(_data)
        {
            delete _data;
            _data = nullptr;
        }

        _data = data;
    }

    //不允许复制或者赋值
    RAII(const RAII &rhs) = delete;
    RAII &operator=(const RAII &rhs) = delete;
private:
    T *_data;
};

int main(int argc, char **argv)
{
    RAII<int> raii(new int(10));//栈对象的生命周期

    cout << endl;
    RAII<Point> pt(new Point(1, 3));//栈对象的生命周期
    pt->print();
    (*pt).print();
    pt.get();
    pt.reset(new Point(1, 4));

    cout << endl;
    /* RAII<Point> pt2 = pt;//error */
    return 0;
}


