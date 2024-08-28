#include "mai.h"

using namespace std;

long long Fib1(long long num){
    if((num == 1 || num == 0)){
        return num;
    }
    return Fib1(num - 1) + Fib1(num - 2);
}

long long Fib2(long long num){
    long long *array = new long long[num+1];
    array[0] = 0;
    array[1] = 1;
    for(int i = 2; i <= num; i++){
        array[i] = array[i - 1] + array[i - 2];
    }
    return array[num];
}

int main()
{
    int i;
    cin >> i;
    cout << Fib2(i) << endl;
    return 0;
}

