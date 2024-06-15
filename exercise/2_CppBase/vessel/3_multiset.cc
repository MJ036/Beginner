#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

template <typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

void test_multiset(){
    multiset<int> number = {1, 3, 9, 8, 3, 4, 2, 3, 8, 1};
    display(number);

    cout << endl << "multiset查找操作" << endl;
    size_t cnt = number.count(8);
    cout << "cnt = " << cnt << endl;

    auto it = number.find(7);
    if(it == number.end())
    {
        cout << "该元素不在multiset中" << endl;
    }
    else
    {
        cout << "该元素存在multiset中 " << *it << endl; 
    }

    cout << "bound" << endl;
    it = number.lower_bound(3);
    cout << "*it = " << *it << endl;
    auto it2 = number.upper_bound(3);
    cout << "*it2 = " << *it2 << endl;

    pair<multiset<int>::iterator,multiset<int>::iterator> ret = number.equal_range(3);
    while(ret.first != ret.second){
        cout << *ret.first << " ";
        ++ret.first;
    }
    cout << endl;



    cout << endl << "insert操作"<< endl;
    number.insert(7);
    display(number);

    cout << endl;
    vector<int> vec = {5, 10, 40, 20, 8, 2};
    number.insert(vec.begin(), vec.end());
    display(number);    

    cout << endl << "erase操作" << endl;
    it = number.begin();
    ++it;
    ++it;
    cout << "*it = " << *it << endl;
    number.erase(it);
    display(number);
}



int main()
{
    test_multiset();
    return 0;
}

