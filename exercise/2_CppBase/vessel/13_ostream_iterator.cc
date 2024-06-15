#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;
using std::copy;

void test(){
    vector<int> vec = {1,3,5,7,2};
    ostream_iterator<int> osi(cout,"\n");
    copy(vec.begin(),vec.end(),osi);
}

int main()
{
    test();
    return 0;
}

