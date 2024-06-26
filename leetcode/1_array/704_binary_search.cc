#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int search(vector<int> &nums, int target){
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int middle = left + ((right - left)/2);
            if(nums[middle] > target){
                right = middle - 1;
            }else if(nums[middle] < target){
                left = middle + 1;
            }else{
                return middle;
            }
        }
        return -1;
    }
};

class my_solution{
public:
    int search(vector<int> &nums,int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int middle = left + ((right - left)/2);
            if(nums[middle] < target){
                left = middle + 1;
            }else if(nums[middle] > target){
                right = middle - 1;
            }else{
                return middle;
            }
        }
        return -1;
    }
};


int main()
{
    vector<int> number1 = {-1,0,3,5,9,12};
    int target = 9;
    my_solution sls;
    cout << sls.search(number1,target) << endl;
    
}

