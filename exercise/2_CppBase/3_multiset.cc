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

    cout << endl << "insert操作"<< endl;
    number.insert(7);
    display(number);

    cout << endl;
    vector<int> vec = {5, 10, 40, 20, 8, 2};
    number.insert(vec.begin(), vec.end());
    display(number);    

}



int main()
{
    test_multiset();
    return 0;
}

