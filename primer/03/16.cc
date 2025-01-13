#include "mai.h"

using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10,42);
    vector<int> v4{10};
    vector<int> v5{10,42};
    vector<string> v6(10);
    vector<string> v7(10,"hi");

    for(auto num : v1){
        cout << num << " ";
    }
    cout << endl;

    for(auto num : v2){
        cout << num << " ";
    }
    cout << endl;

    for(auto num : v3){
        cout << num << " ";
    }
    cout << endl;

    for(auto num : v4){
        cout << num << " ";
    }
    cout << endl;

    for(auto num : v5){
        cout << num << " ";
    }
    cout << endl;

    for(auto num : v6){
        cout << num << " ";
    }
    cout << endl;

    for(auto num : v7){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

