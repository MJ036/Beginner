#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i,j,k;
        vector<int> results(nums.size(),0);
        for(k = nums.size()-1,i = 0,j = nums.size() - 1;i <= j ;){
            if(nums[i]*nums[i] > nums[j]*nums[j]){
                results[k--] = nums[i]*nums[i];
                i++;
            }else{
                results[k--] = nums[j]*nums[j];
                j--;
            }
        }
        return results;
    }

};

int main()
{
    
}

