#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n%10) *(n%10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> result;
        int num = getSum(n);
        while(num != 1){
            if(result.find(num) != result.end()){
                return false;
            }
            result.insert(num);
            num = getSum(num);   
        }
        return true;
    }

    bool isHappy2(int n){
        unordered_set<int>  result;
        while(1){
            int sum = getSum(n);
            if(sum == 1){
                return true;
            }
            if(result.find(sum) != result.end()){
                return false;
            }else{
                result.insert(sum);
            }
            n = sum;
        }

    }

    int getSum2(int n){
        int sum = 0;
        while(n){
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy3(int n){
        unordered_set<int> set;
        while(1){
           int sum =  getSum2(n);
           if(n == 1){
               return true;
           }
           if(set.find(sum) != set.end()){
               return false;
           }else{
               set.insert(sum);
           }
           n = sum;
        }
    }


};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

