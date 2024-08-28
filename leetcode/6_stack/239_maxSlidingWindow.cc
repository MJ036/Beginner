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

class solution_agagi{
public:
    class Myqueue{
    public:
        void pop(int value){
            if(!que.empty() && value == que.front()){
                que.pop_front();
            }
        }
        void push(int value){
            while(!que.empty() && value > que.front()){
                que.pop_back();
            }
            que.push_back(value);
        }

        int front(){
            return que.front();
        }
    private:
            deque<int> que;

    };

public:
    vector<int> MaxSlidingWindows(vector<int>& nums, int k){
        Myqueue que;
        vector<int> max;
        for(int i = 0; i < k; i++){
            que.push(nums[i]);
        }
        for(int i = k; i <(int) nums.size(); i++){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            max.push_back(que.front());
        }
        return max;

    }
};
