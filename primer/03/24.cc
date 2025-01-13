#include "mai.h"

using namespace std;

//相邻整数的和
void test(vector<int> vec){

    for(auto it = vec.begin(); it+1 != vec.end(); it++){
        cout << *it + *(it + 1) << endl;
    }

}

//前后元素的和
void test1(vector<int> vec){

    //业务
    for(auto it = vec.begin(),it2 = vec.end()-1; it <= it2; it++,it2--){
        cout << *it + *it2 << "\n";
    }
}

int main()
{
    vector<int> vec;
    int i = 0;
    //读取数据
    while(cin >> i){
        vec.push_back(i);
    }
    test(vec);
    test1(vec);

    return 0;
}

