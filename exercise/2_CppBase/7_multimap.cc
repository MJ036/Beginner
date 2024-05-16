#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <math.h>

using namespace std;

template <typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem.first << "  " << elem.second << endl;
    }
}

void test_multimap_CRUD(){
    multimap<int,string> number = {
        {1,"bejing"},
        {19,"beijing"},
        pair<int,string>(3,"nanjing"),
        make_pair(4,"wuhan"),
        make_pair(19,"wuhan"),
    };
    display(number);

    cout << endl << "multimap查找操作" << endl;
    size_t cnt = number.count(8);
    cout << "cnt = " << cnt << endl;

    auto it = number.find(7);
    if(it == number.end())
    {
        cout << "该元素不在multimap中" << endl;
    }
    else
    {
        cout << "该元素存在multimap中 " << it->first 
             << "    " << it->second << endl; 
    }
    cout << "insert" << endl;
    number.insert(make_pair(5,"dongjing"));
    display(number);

#if 0

    cout << endl << "multimap的下标操作" << endl;
    cout << "number[1] = " << number[1] << endl;//查找
    cout << "number[8] = " << number[8] << endl;
    display(number);    

    cout << endl;
    //T &operator[](const Key &)
    number[8] = "hainan";//修改
    number[10] = "hainan";
    display(number);

    multimap<int,string> mm = {{1,"wuhan"}};
    cout << "mm[1] = " << mm[1]  << endl;
#endif
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

std::ostream &operator<<(std::ostream &os,const Point &rhs)
{
    os << "(" << rhs._ix
        << "," << rhs._iy
        << ")";

    return os;
}

void test_multimap_overload(){
    map<string,Point> number = {
        {"bejing",Point(1,2)},
        {"nanjing",Point(1,-2)},
        pair<string,Point>("hubei",Point(-1,2)),
        pair<string,Point>("hubei",Point(10,2)),
        make_pair("hainan",Point(3,3))
    };
    display(number);
}

int main()
{
    /* test_multimap_CRUD(); */   
    test_multimap_overload();
    return 0;
}

