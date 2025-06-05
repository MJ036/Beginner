#include "mai.h"
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> results;

    void backtracing(vector<int>& candidates, int target, int startIndex, int sum){
        if(sum > target){
            return;
        }   
        if(sum == target){
            results.push_back(path);
            return;
        }   
        for(int i = startIndex; i < candidates.size() && (sum + candidates[i]) <= target; i++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracing(candidates,target,i,sum);
            sum -= candidates[i];
            path.pop_back();
        }   
    }   
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        path.clear();
        results.clear();
        backtracing(candidates,target,0,0);
        return results;                                                                                     
                                                                                                            
    }   
};
