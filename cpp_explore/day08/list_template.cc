#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem << " "; 
    }
    cout << endl;
}

void test()
{
    list<int> number = {1,3,5,7,9,8,6,4,2,19};
    display(number);
    cout << endl << "在list尾部插入删除" << endl;
    number.push_front(199);
    number.push_front(200);
    display(number);
    number.pop_front();
    display(number);

    cout << endl << "insert of list at any position" << endl;
    auto it = number.begin();
    ++it;
    ++it;
    cout << "*it = " << *it << endl;
    /* number.insert(it,11); */
    /* number.insert(it,5,22); */
    /* vector<int> vec = {100,200,300,400}; */
    /* number.insert(it,vec.begin(),vec.end()); */
    number.insert(it,{000,999,555,444});
    display(number);
    cout << "*it = " << *it << endl;
    
}

int main()
{
    test();
    return 0;
}

