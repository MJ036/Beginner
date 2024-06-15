#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::ostream_iterator;
using std::istream_iterator;
using std::vector;
using std::copy;


class Point{
public:
    Point(){
        cout << "Point()" << endl;
    }

    ~Point(){
        cout << "~Point()" << endl;
    }
};

void test1(){
    Point ();
    cout << "1" << endl;
    Point pt;
    /* pt.~Point(); */
    cout << "2" << endl;
}


void test(){
    vector<int> vec;

    istream_iterator<int> isi(cin);
    cout << " 2 " << endl;
    copy(isi,istream_iterator<int>(),back_inserter(vec));

    cout << "vec.size() = "  << vec.size() << endl;
    copy(vec.begin(),vec.end(),ostream_iterator<int>(cout, " "));
    
    cout << endl;

}

int main()
{
    test1();
    return 0;
}

