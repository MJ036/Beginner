#include <iostream>

using namespace std;
class Point
{
public:
    Point(int ix = 0, int iy = 0)
        :_ix(ix)
         ,_iy(iy)
    {
        cout << "Point(int = 0,int = 0)" << endl;
    }

    void print() const
    {
        cout << "(" << _ix
            << "," << _iy
            << ")";
        cout << endl;
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

std:: ostream &operator<<(std::ostream &os, const Point &rhs)
{
    os << "(" << rhs._ix << "," << rhs._iy << ")";
    return os;
}

template <typename T>
class RAII
{
public:
    RAII(T *data)
        :_data(data)
    {
        cout << "RAII(T *)" << endl;
    }
    
    ~RAII(){
        cout << "~RAII()" << endl;
        if(_data){
            delete  _data;
            _data = nullptr;
        }
    }

    T *operator->(){
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
        if(_data){
            delete  _data;
            _data = nullptr;
        }
        _data = data;
    }

    RAII(const RAII &rhs) = delete;
    RAII &operator=(const RAII &rhs) = delete;


private:
    T *_data;
};

int main()
{
    RAII<int> raii(new int(10));
    cout << endl;
    RAII<Point> pt(new Point(1,2));
    pt->print();
    (*pt).print();
    pt.get();
    pt.reset(new Point(1,4));

    cout << endl;
    /* RAII<Point> pt2 = pt; */

    return 0;
}

