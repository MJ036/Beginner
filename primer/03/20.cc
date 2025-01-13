#include "mai.h"

using namespace std;

void test(vector<int> vec){

    for(int i = 0; i < vec.size()-1; i++){
        cout << vec[i] + vec[i+1] << endl;
    }

}

void test1(vector<int> vec){
    //业务
    for(int i = 0; i < vec.size()/2; i++){
        cout << vec[i] + vec[vec.size()-1 -i] << "\n";
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

