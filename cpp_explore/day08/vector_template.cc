#include <iostream>
#include <vector>

using namespace std;

template<typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem << " "; 
    }
    cout << endl;
}

void printCapaticy(const vector<int> &con)
{
    cout << "size() = " << con.size() << endl;
    cout << "capacity() = " << con.capacity() << endl;
}

void test()
{
    vector<int> number = {1,3,5,7,9,8,6,0,12,13};
    number.reserve(20);
    display(number);
    printCapaticy(number);
    
    cout << endl << "insert of vector at end" << endl;
    number.push_back(100);
    number.push_back(200);
    display(number);
    printCapaticy(number);
    /* cout << endl << "在vector头部插入删除" << endl; */
    /* number.push_front(199); */
    /* number.push_front(200); */
    /* display(number); */
    /* number.pop_front(); */
    /* display(number); */

    cout << endl << "insert of vector at any position" << endl;
    auto it = number.begin();
    ++it;
    ++it;
    cout << "*it = " << *it << endl;
    number.insert(it,11);
    display(number);
    printCapaticy(number);
    cout << "*it = " << *it << endl;

    number.insert(it,5,22);
    display(number);
    printCapaticy(number);
    cout << "*it = " << *it << endl;
    it = number.begin();
    ++it;
    ++it;
    
    vector<int> vec = {100,200,300,400};
    number.insert(it,vec.begin(),vec.end());
    display(number);
    printCapaticy(number);
    cout << "*it = " << *it << endl;
    it = number.begin();
    ++it;
    ++it;
    
    number.insert(it,{000,999,555,444});
    display(number);
    printCapaticy(number);

    cout << "clean element" << endl;
    number.clear();
    printCapaticy(number);
    



    
}
    class Point
    {
    public:
        Point(int ix = 0, int iy = 0)
            :_ix(ix)
             ,_iy(iy)
        {
            cout << "Point(int = 0, int = 0)" << endl;
        }
        Point(const Point &rhs)
            :_ix(rhs._ix)
             ,_iy(rhs._iy)
        {
            cout << "Point(const Point &)" << endl;
        }
    private:
            int _ix;
            int _iy;
    };
    void test2()
    {
        vector<Point> vec;
        /* vec.push_back(Point(1,2)); */
        vec.emplace_back(1,2);
    }
    

int main()
{
    test2();
    return 0;
}

