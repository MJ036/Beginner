#include "mai.h"
using namespace std;

class Solution {
private:
    //存结果
    vector<vector<int>> results;
    //存当前路径。符合条件时加入结果
    vector<int> path;

    void backtracing(int n, int k, int startIndex){
        if(path.size() == k){ 
            results.push_back(path);
            return;
        }   
        for(int i = startIndex; i <= n; i++){
            path.push_back(i);
            backtracing(n,k,i + 1); 
            path.pop_back();
        }   

    }   
public:
    vector<vector<int>> combine(int n, int k) {
        results.clear();
        path.clear();
        backtracing(n,k,1);
        return results;
    }                                                                               
};
