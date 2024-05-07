#include <iostream>
#include <list>

using namespace std;

template <typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem << " ";
    }
    cout << endl;
}

struct CompareList
{
    bool operator()(const int &lhs, const int &rhs)const
    {
        //从大到小排序
        return lhs > rhs;
    }
};

void test()
{
    list<int> number = {1,4,6,8,17,11,25,12,5,6,6,6};
    display(number);
    
    cout << endl << "unique test" << endl;
    number.unique();
    display(number);

    cout << endl << "reverse test" << endl;
    number.reverse();
    display(number);

    cout << endl << "sort test" << endl;
    number.sort(CompareList());
    display(number);


    cout << endl << "merge test" << endl;
    list<int> number2 = {10,2,6,5,29};
    number2.sort();
    display(number2);
    number.merge(number2);
    display(number);
    number.unique();
    display(number);

}

void test2()
{
    list<int> number = {1, 3, 8, 5, 7, 9};
    list<int> number2 = {11, 33, 88, 55, 77, 99};
    display(number);
    display(number2);

    cout << endl << endl;
    auto it = number.begin();
    ++it;
    ++it;
    //number.splice(it,number2);
    
    auto it2 = number2.end();
    --it2;
    number.splice(it,number2,it2);

    display(number);
    display(number2);

    cout << endl << endl;
    it2 = number2.begin();
    auto it3 = number2.end();
    --it3;
    --it3;
    cout << "it:1,2,3  " <<  *it << " " << *it2 << " " << *it3 << endl; 
    number.splice(it,number2,it2,it3);
    display(number);
    display(number2);


    
}

int main()
{
    test();

    return 0;
}

