#include "mai.h"
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> results;

    void backtracing(vector<int>& nums,vector<bool>& used){
        if(path.size() == nums.size()){
            results.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(used[i] == true){
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracing(nums,used);
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        results.clear();
        vector<bool> used(nums.size(),false);
        backtracing(nums,used);
        return results;
        
    }
};
