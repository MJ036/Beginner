#include <iostream>
#include <vector>

using namespace std;

void test(){
 //   vector<int> number;
 //   vector<int> number(10,3);
 //   vector<int> number(10);
    /* int arr[10] = {1,3,5,7,8}; */
    /* vector<int> number(arr,arr + 5); */

    vector<int> number = {1,2,3,4,5,6,7,8};

    for(size_t idx = 0; idx != number.size(); ++idx)
    {
        cout << number[idx] << " ";
    }
    cout << endl;

    vector<int>::iterator it;
    for(it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<int>::iterator it2 = number.begin();
    for(; it2 != number.end(); ++it2)
    {
        cout << *it2 << " ";
    }
    cout << endl;

    for(auto &elem : number){
        cout << elem << " ";
    }
    cout << endl;

}

int main()
{
    test();
    return 0;
}

