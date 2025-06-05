#include "mai.h"
using namespace std;

class Solution {
    int num1 = 0;
    int num2 = 0;
public:
    int differenceOfSums(int n, int m) {
        for(int i = 0; i <= n; i++){
            if(i % m == 0){
                num2 += i;
            }else{
                num1 += i;
            }
        }
        return num1 - num2;
    }
};
