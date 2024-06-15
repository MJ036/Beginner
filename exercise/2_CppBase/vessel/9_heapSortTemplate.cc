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
    void print();
private:
    vector<T> _vec;
};

template<class T,class Compare>
HeapSort<T,Compare>::HeapSort(T *arr,size_t size,Compare com){
    for(size_t i = 0; i < size; ++i){
        _vec.push_back(arr[i]);
    }

    for(int i = size/2 -1; i>=0 ;i-- ){
        heapAdjust(i,size,com);
    }
    swap(arr[0],arr[size - 1]);
    sort(com);
}

template<class T,class Compare>
void HeapSort<T,Compare>::heapAdjust(size_t adjustpos,size_t arrlen,Compare &com){
    size_t dad = adjustpos;
    size_t son = 2 * dad + 1;
    
    while(son < arrlen){
        if(son + 1 < arrlen && com(_vec[son],_vec[son+1])){
            ++son;
        }
        if(com(_vec[dad],_vec[son])){
            swap(_vec[dad],_vec[son]);
            dad = son;
            son = 2 * dad + 1;
        }
        else{
            break;
        }
    }
}

template <class T,typename Compare>
void HeapSort<T,Compare>::sort(Compare &com){
    size_t size = _vec.size();
    for(size_t i = size; i > 1 ; --i){
        heapAdjust(0,i,com);
        swap(_vec[0],_vec[i - 1]);
    }
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
    int arr[10] = {1, 2, 6, 3, 4, 8, 5, 7, 9, 10};
    HeapSort<int> hs(arr, 10, std::less<int>());
    hs.print();

    cout << endl;
    Point parr[5] = {{1,2}, {3,4}, {-1,2}, {4,5}, {2,5}};

    HeapSort<Point> hsPt(parr, 5, std::less<Point>());
    hsPt.print();

    return 0;
    return 0;
}

