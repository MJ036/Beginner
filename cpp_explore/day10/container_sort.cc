#include <iostream>
#include <list>

using namespace std;

struct CompareList
{
    bool operator()(const int &lhs, const int &rhs) const
    {
        cout << "bool operator()" << endl;
        return lhs < rhs;
    }
};

void display(const list<int> &rhs){
    for(auto &elem : rhs){
        cout << elem << " ";
    }
    cout << endl;
}

void test(){
    list<int> vec = {1,3,7,4,0,19};
    vec.sort(CompareList());
    display(vec);
}

int main()
{
    test();

    return 0;
}

