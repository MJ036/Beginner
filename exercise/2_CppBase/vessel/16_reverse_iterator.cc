#include <iostream>
#include <iterator>
#include <vector>

using std::cout ;
using std::endl;
using std::reverse_iterator;
using std::vector;

void test(){
    vector<int> vec = {11, 33, 55, 77, 66, 1, 2};
    vector<int>::iterator it = vec.begin();
    for(; it != vec.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

void test2(){
    vector<int> vec = {11, 33, 55, 77, 66, 1, 2};
    vector<int>::reverse_iterator rit = vec.rbegin();
    for(; rit != vec.rend(); ++rit){
        cout << *rit << " ";
    }
    cout << endl;
}

int main()
{
    test();
    test2();
    return 0;
}

