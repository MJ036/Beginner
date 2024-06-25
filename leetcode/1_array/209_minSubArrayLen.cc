#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int sum = 0;
        int result = __INT32_MAX__;
        int subLength = 0;
        for(int j = 0; j < (int)nums.size();j++){
            sum += nums[j];
            while(sum >= target){
                subLength = j - i + 1;
                result = result < subLength ? result : subLength;
                sum -= nums[i++];
            }
        }
        return result == __INT32_MAX__ ? 0 : result;
    }

};

int main()
{
    cout << __INT32_MAX__ << endl;
}

