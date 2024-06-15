#include <iostream>
#include <vector>

using namespace std;

void test_initiate(){
    vector<int> number;
    
    vector<int> number2(10,3);
    
    int arr[5] = {1,3,5,7,0};
    vector<int> number3(arr,arr+5);

    vector<int> number4 = {1,2,3,4,5};

    for(size_t idx = 0; idx != number3.size(); ++idx){
        cout << number3[idx] << " ";
    }
    cout << endl;

    for(auto &elem : number3){
        cout << elem << " ";
    }
    cout << endl;

    vector<int>::iterator it;
    for(it = number3.begin(); it != number3.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}


int main()
{
    test_initiate();
    return 0;
}

