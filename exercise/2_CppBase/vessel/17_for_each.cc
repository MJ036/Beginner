#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::for_each;
using std::copy;
using std::vector;
using std::ostream_iterator;


void func(int &value){
    ++value;
    cout << value << "";
}

void test(){
    vector<int> vec = {1, 3, 7, 9, 5, 8};
    copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    /* for_each(vec.begin(),vec.end(),func); */
    for_each(vec.begin(),vec.end(),[](int &value){
             ++value;
             cout << value << " ";
             });
    cout << endl;
    
    copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
    cout << endl;


}


int main()
{
    test();
    return 0;
}

