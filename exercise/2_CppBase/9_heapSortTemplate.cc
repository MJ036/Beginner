#include <iostream>
#include <math.h>
#include <vector>
#include <ostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

template<class T>
void swap(T &lhs,T &rhs){
    auto temp = lhs;
    lhs = rhs;
    rhs = temp;
}

class Point{
public:
    Point(int x = 0, int y = 0): _x(x),_y(y){}

    ~Point(){}

    void print() const{
        cout << "(" << _x << "," << _y << ")" << endl;
    }
    
    double getDistance() const{
        return hypot(_x,_y);
    }
    
    int getX() const{
        return _x;
    }
    
    int getY() const{
        return _y;
    }
    
    friend std::ostream & operator<<(std::ostream &os, const Point &rhs);

private:
    double _x;
    double _y;
};

std::ostream & operator<<(std::ostream &os,const Point &rhs){
    os << "(" << rhs._x << "," << rhs._y << ")";
    return os;
}

bool operator<(const Point &lhs,const Point &rhs){
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

template<class T, class Compare = std::less<T>>
class HeapSort{
public:
    HeapSort(T *arr,size_t size,Compare);
    void heapAdjust(size_t,size_t,Compare&);
    void sort(Compare&);
private:
    vector<T> _vec;
};

template<class T,class Compare>
HeapSort<T,Compare>::HeapSort(T *arr,size_t size,Compare){
    for(size_t i = 0; i < size; ++i){
        _vec.push_back(arr[i]);
    }

    for(int i = size/2 -1; ; ){

    }
}




template <class T,typename Compare>
void HeapSort<T,Compare>::sort(Compare &com){

}


template<class T,class Compare>
void HeapSort<T,Compare>::print(){
    for(auto &elem : _vec){
        cout << elem << " ";
    }
    cout << endl;
}


int main()
{
    return 0;
}

