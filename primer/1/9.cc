#include <iostream>

using namespace std;

int main()
{
    //1.9
    int val = 50;
    int sum = 0;
    while(val <= 100){
        sum += val;
        ++val;
    }
    cout << sum << endl;
    cout << endl;
//1.10
    sum = 0;
    val = 10;
    while(val >= 0){
        cout << val << " ";
        --val;
    }
    cout << endl;
//1.11
    cout << "输入两个整数：" << endl;
    int num1,num2;
    cin >> num1 >> num2 ;
    while(num1 <= num2){
        cout << num1;
        ++num1;
        cout << " ";
    }
    cout << endl;
    return 0;
}

