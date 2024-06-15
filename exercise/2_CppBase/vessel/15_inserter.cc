#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::back_inserter;
using std::back_insert_iterator;
using std::front_inserter;
using std::front_insert_iterator;
using std::inserter;
using std::insert_iterator;
using std::vector;
using std::list;
using std::set;
using std::copy;

void test(){
    vector<int> vecNumber = {1,3,7,9,5};
    list <int>lstNumber = {2,4,8,10,6};
    copy(lstNumber.begin(),lstNumber.end(),back_insert_iterator<vector<int>>(vecNumber));

    copy(vecNumber.begin(),vecNumber.end(),ostream_iterator<int>(cout," "));

    cout  << endl;

    copy(vecNumber.begin(),vecNumber.end(),front_insert_iterator<list<int>>(lstNumber));
    copy(lstNumber.begin(),lstNumber.end(),ostream_iterator<int>(cout," "));

    cout << endl;
    set<int> setNumber = {1, 10, 40, 50, 90, 12};
    auto it = setNumber.begin();
    copy(vecNumber.begin(),vecNumber.end(),inserter<set<int>>(setNumber,it));
    copy(setNumber.begin(),setNumber.end(),ostream_iterator<int>(cout, " "));
    cout << endl;


}

int main()
{
    test();
    return 0;
}

