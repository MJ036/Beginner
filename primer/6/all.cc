#include "mai.h"

using namespace std;

void test_3(){
    int n ;
    cout << "Enter a num:";
    cin >> n;
    int ret  = 1;
    while(n > 1){
        ret *= n--;
    }
    cout << "fact(n) = " << ret << endl;
}

void test_5(){
    cout << "Enter a num:";
    int n;
    cin >> n;
    cout << "abs of num: " << abs(n) << endl;
}

void test_7(){
    static int cnt = 0;
    cout << "cnt = " << cnt  << endl;
    cnt++;
}

int main()
{
    test_3();
    test_5();
    for(int i = 0; i < 10; i++){
        test_7();
    }
    return 0;
}

