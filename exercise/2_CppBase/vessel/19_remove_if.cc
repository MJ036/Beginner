#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::for_each;
using std::remove_if;
using std::copy;
using std::vector;
using std::ostream_iterator;

bool func(int value){
    return value > 4;
}

void test(){
    vector<int> vec = {1, 3, 4, 6, 8, 5, 3, 2};
    for_each(vec.begin(),vec.end(),[](int &value){
            cout << value << " ";
             });
    cout << endl;

    auto it = remove_if(vec.begin(),vec.end(),bind2nd(std::greater<int>(),4));
    vec.erase(it,vec.end());
    cout << endl;

    for_each(vec.begin(), vec.end(), [](int &value){
             cout << value << "  ";
             });
    cout << endl;

}




int main()
{
    test();
    return 0;
}

