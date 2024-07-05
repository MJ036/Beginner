#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int k=0; k < nums.size(); k++){
            if(nums[k] > target && nums[k] >= 0){
                break;
            }
            if(k > 0 && nums[k] == nums[k-1]){
                continue;
            }
            for(int i = k+1; i < nums.size(); i++){
                if(nums[k] + nums[i] > target && nums[k] + nums[i] >= 0){
                    break;
                }
                if(i > k+i && nums[i] == nums[i-1]){
                    continue;
                }
                int left = i+1;
                int right = nums.size() - 1;
                while(left < right){
                    if((long)nums[k]+nums[i]+nums[left]+nums[right] > target){
                        right--;
                    }else if((long)nums[k]+nums[i]+nums[left]+nums[right] < target){
                        left++;
                    }else{
                        result.push_back(vector<int>{nums[k],nums[i],nums[left],nums[right]});
                        while(left < right && nums[left] == nums[left+1]){
                            left++;
                        }
                        while(left < right && nums[right] == nums[right-1]){
                            right--;
                        } 
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < (int)nums.size(); i++){
            if(nums[i] > 0){
                return result;
            }
            if(i > 0 && (nums[i] == nums[i-1])){
                continue;
            }
            int left = i+1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }else{
                    result.push_back(vector<int> {nums[i],nums[left],nums[right]});
                    while(left < right && (nums[right] == nums[right - 1])){
                        right--;
                    }
                    while(left < right && (nums[left] == nums[left + 1])){
                        left++;
                    }
                    right--;
                    left++;
                }

            }
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

