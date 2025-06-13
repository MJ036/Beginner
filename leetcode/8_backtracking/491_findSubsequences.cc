#include "mai.h"
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> results;

    void backtracing(vector<int>& nums, int startIndex){
        if(path.size() > 1){
            results.push_back(path);
        }

        unordered_set<int> uset;
        for(int i = startIndex; i < nums.size(); ++i){
            if(!path.empty() && nums[i] < path.back() || uset.find(nums[i]) != uset.end()){
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracing(nums,i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        results.clear();
        backtracing(nums,0);
        return results;
        
    }
};
