#include "mai.h"

using namespace std;

class Solution {
public:
    class mycomparison{
        public:
            bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs){
                return lhs.second > rhs.second;
            }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto it : nums){
            map[it]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomparison> pri_que;

        for(auto it : map){
            pri_que.push(it);
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }

        vector<int> result(k);
        for(int i = k-1; i >=0; --i){
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

int main(){
    vector<int> vec = {1,1,1,2,2,3};
    int k = 2;
    Solution sol;
    vector<int> res = sol.topKFrequent(vec,k);
    for(auto num : res){
        cout << num << ",";
    }
    cout << endl;
}
