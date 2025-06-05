#include "mai.h"
using namespace std;

class Solution {
private:
    void backtracing(int targetSum, int k, int index,int sum){
        if(sum > targetSum){
            return;
        }
        if(k == path.size()){
            if(sum == targetSum){
                results.push_back(path);
                return;
            }
        }
        for(int i = index; i <= 9 - (k - path.size()) + 1; i++){
            sum += i;
            path.push_back(i);
            backtracing(targetSum,k,i+1,sum);
            sum -= i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        path.clear();
        results.clear();
        backtracing(n,k,1,0);
        return results;
    }

private:
    vector<int> path;
    vector<vector<int>> results;

};
