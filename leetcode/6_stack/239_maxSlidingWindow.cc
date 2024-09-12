#include "mai.h"

using namespace std;

class Solution {
private:

class Myqueue{
public:
    deque<int> que;
    void pop(int value){
        if(!que.empty() && value == que.front()){
            que.pop_front();
        }
    }

    void push(int value){
        while(!que.empty() && value > que.back()){
            que.pop_back();
        }
        que.push_back(value);
    }

    int front(){
            return que.front();
    }
};

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Myqueue que;
        vector<int> result;
        for(int i = 0; i < k ; i++){
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for(int i = k; i < nums.size(); i++){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};



class Solution3{
    class Myqueue{
        deque<int> que;
    public:
        void pop(int value){
            if(!que.empty() && que.front() == value){
                que.pop_front();
            }
        }

        void push(int value){
            while(!que.empty() && que.back() < value){
                que.pop_back();
            }
            que.push_back(value);
        }
        
        int front(){
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        Myqueue que;
        for(int i = 0; i < k; ++i){
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for(int i = k; i < nums.size(); ++i){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
