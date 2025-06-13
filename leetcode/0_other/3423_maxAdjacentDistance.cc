#include "mai.h"
#include <cstdlib>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxNum = abs(nums[0]- nums.back());
        for(int i = 1; i < nums.size(); ++i){
            maxNum = max(abs(nums[i] - nums[i-1]), maxNum);
        }
        return maxNum;
    }
};
