#include <iostream>
#include <set>
#include <vector>

using std::set;
using std::cout;
using std:: endl;
using std::vector;

void test(){

    std::cout << "Hello world" << std::endl;
    set<int> my_set = {1,11,2,22,3,33,4,55};
    for(auto &elem : my_set){
        cout << elem << " ";
    }
    cout << endl;
    auto it = my_set.find(2);
    cout << *it << endl;
}

void test2(){
    vector<int> vec;
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout <<endl;
}

int main()
{
    test2();
}

