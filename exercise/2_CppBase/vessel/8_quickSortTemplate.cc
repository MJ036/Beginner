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

template<class T,class Compare = std::less<T>>
class MyQsort
{
public:
    MyQsort(T *arr,size_t size,Compare com);
    void quick(int left,int right, Compare &);
    int partition(int left,int right,Compare &);
    void print();
private:
    vector<T> _vec;
};

template<class T,class Compare>
MyQsort<T,Compare>::MyQsort(T *arr,size_t size,Compare com){
    for(size_t i = 0; i < size; ++i){
        _vec.push_back(arr[i]);
    }
    quick(0,_vec.size(),com);
}

template<class T,class Compare>
void MyQsort<T,Compare>::quick(int left,int right,Compare &com){
    int pivot;
    if(left < right){
        pivot = partition(left,right,com);
        quick(left,pivot - 1,com);
        quick(pivot + 1,right,com);
    }
}

template<class T,class Compare>
int MyQsort<T,Compare>::partition(int left,int right,Compare &com){
    int index_d,index_s;
    for(index_d = left,index_s = left; index_d < right; ++ index_d){
        if(com(_vec[index_d],_vec[right])){
            swap<T>(_vec[index_d],_vec[index_s]);
            ++index_s;
        }
    }
    swap(_vec[index_s],_vec[right]);
    return index_s;
}

template<class T,class Compare>
void MyQsort<T,Compare>::print(){
    for(auto &elem : _vec){
        cout << elem << " ";
    }
    cout << endl;
}


int main()
{
    int arr[10] = {1, 2, 4, 5, 8, 6, 3, 7, 10, 9} ;
    MyQsort<int> mqInt(arr,10,std::less<int>());
    mqInt.print();
    
    Point par[5] = {Point(1,2), Point(3,4), Point(-1,2), Point(4,5), Point(2,5)};
    MyQsort<Point> mqPt(par,5,std::less<Point>());
    mqPt.print();

    return 0;
}

