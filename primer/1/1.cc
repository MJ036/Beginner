#include <iostream>
#include "Sales_item.h"

using namespace std;

void test_1_9(){
    int i = 50,sum = 0;
    while(i <= 100){
        sum += i;
        i++;
    }
    cout << sum << endl;
}

void test_1_10(){
    int i = 10, sum = 0;
    while(i > 0){
        sum += i;
        i--;
    }
    cout << sum << endl;
}

void test_1_11(){
    int i,j,sum = 0;
    cin >> i >> j;
    if(i > j){
        int temp = j;
        j = i;
        i = temp;
    }
    while(i <= j){
        sum += i;
        i++;
    }
    cout << sum << endl;
}

void test_1_12(){
    int sum = 0;
    for(int i = -100; i <= 100; ++i){
        sum += i;
    }
    cout << sum <<endl;

}
void test_1_16(){
    float a,sum = 0;
    while(cin >> a){
        sum += a;
    }
    cout << sum ;
}

void test_1_18(){
    int curVal = 0, val = 0;
    if(cin >> curVal){
        int cnt = 1;
        while(cin >> val){
            if(val ==curVal){
                cnt++;
            }
            else{
                cout << curVal << " occurs " << cnt << " times" << endl;
                curVal = val;
                cnt = 1;
            }
        }
        cout << curVal << " occurs " << cnt << " times " << endl;
    }
}

void test_1_20(){
    Sales_item item1;
    cin >> item1;
    cout << item1 << endl;

}

void test_1_21(){
    Sales_item item1,item2;
    cin >> item1 >> item2;
    cout << item1+item2 << endl;

}

void test_1_22(){
    Sales_item curitem,item;
    if(cin >> curitem){
        while(cin >> item){
            if(item.isbn() ==curitem.isbn()){
                curitem += item;
            }
            else{
                cout << curitem ;
                curitem = item;
            }
        }
        cout << curitem;
    }
    else{
        cerr << "no data" << endl;
    }
}

void test1_22_again(){
    Sales_item curitem,item;
    if(cin >> curitem){
        while(cin >> item){
            if(item == curitem){
                curitem += item;
            }else{
                cout << curitem << endl;
                curitem = item;
            }
        }
        cout << item << endl;
    }else{
        cerr << "no data" << endl;
    }
}


int main()
{
    test_1_22();
    return 0;
}

