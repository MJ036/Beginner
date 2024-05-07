#include <iostream>
#include <set>
#include <utility>
#include <math.h>

using namespace std;

template <typename Container>
void display(const Container &con){
    for(auto &elem : con){
        cout << elem << " ";
    }
    cout << endl;
}

void test_initiate(){
    set<int> number = {1, 3, 9, 8, 4, 2, 3, 8, 1};
    display(number);
    size_t cnt = number.count(10);
    cout << "count = " << cnt << endl; 

    auto it = number.find(7);
    if(it == number.end()){
        cout << "not found" << endl;
    }
    else{
        cout << "found"  << *it << endl;
    }
    
    auto ret = number.insert(7);
    if(ret.second){
        cout << "inserted successfully" << *ret.first << endl;
    }
    else{
        cout << "inserted failedly" << endl;
    }
    display(number);

    it = number.begin();
    ++it;
    ++it;
    cout << "*it = " << *it << endl;
    cout << "before erese" << endl;
    display(number);
    cout << "after erase" << endl;
    number.erase(it);
    display(number);

}

class Point{
public:
    Point(int ix = 0, int iy = 0) : _ix(ix),_iy(iy){}

    float getDistance() const{
        return hypot(_ix,_iy);
    }

    int getX() const {
        return _ix;
    }

    int getY() const {
        return _iy;
    }
    
    friend std::ostream &operator <<(std::ostream &os, const Point &rhs);
    friend bool operator<(const Point &lhs, const Point &rhs);
    friend struct ComparePoint;


private:
    int _ix;
    int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs){
    os << "(" << rhs._ix << "," << rhs._iy << ")";
    return os;
}

//重载" < " ,比较自定义类型Point
bool operator<(const Point &lhs,const Point &rhs){
    cout << "bool operator<" << endl;
    if(lhs.getDistance() < rhs.getDistance()){
        return true;
    }
    else if(lhs.getDistance() == rhs.getDistance()){
        if(lhs.getX() == rhs.getX())
        {
            if(lhs._iy < rhs._iy){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }       
    }
    else{
        return false;
    }
}

namespace std{
template <>
    struct less <Point>{
        bool operator()(const Point &lhs,const Point &rhs) const{
            cout << "template <>" << endl;
            if(lhs.getDistance() < rhs.getDistance()){
                return true;
            }
            else if(lhs.getDistance() == rhs.getDistance()){
                if(lhs.getX() == rhs.getX())
                {
                    if(lhs.getY() < rhs.getY()){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }       
            }
            else{
                return false;
            }

        }
    };
}

struct ComparePoint{
        bool operator()(const Point &lhs,const Point &rhs) const{
            cout << "struct ComparePoint" << endl;
            if(lhs.getDistance() < rhs.getDistance()){
                return true;
            }
            else if(lhs.getDistance() == rhs.getDistance()){
                if(lhs.getX() == rhs.getX())
                {
                    if(lhs.getY() < rhs.getY()){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }       
            }
            else{
                return false;
            }

        }

};

void test_customTypeComparison(){
    /* set<Point> number = { */
    set<Point, ComparePoint> number = {
        Point(1, 2),
        Point(-1, 2),
        Point(1, 2),
        Point(3, 2),
        Point(1, -2),
        Point(4, -2),
    };
    display(number);
}

int main()
{
    /* test_initiate(); */
    test_customTypeComparison();    //三种重载、函数模板、结构体
    return 0;
}

