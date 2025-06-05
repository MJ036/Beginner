#include "mai.h"
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> results;
    void backtracing(vector<int>& nums, int startIndex){
        results.push_back(path);
        for(int i = startIndex; i < nums.size(); ++i){
            if(i > startIndex  && nums[i] == nums[i - 1]){
                continue;
            }
            path.push_back(nums[i]);
            backtracing(nums,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        path.clear();
        results.clear();
        sort(nums.begin(),nums.end());
        backtracing(nums,0);
        return results;
    }
};
