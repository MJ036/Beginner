#include "mai.h"
#include <type_traits>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> results;
    void backtracing(vector<int>& nums, int startIndex){
        results.push_back(path);
        for(int i = startIndex; i < nums.size(); ++i){
            path.push_back(nums[i]);
            backtracing(nums,i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        path.clear();
        results.clear();
        backtracing(nums,0);
        return results;
    }
};
