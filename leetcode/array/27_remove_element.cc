#include <iostream>
#include <vector>

using namespace std;

class my_Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto left = nums.begin();
        while(left != nums.end()){
            if(*left == val){
                left = nums.erase(left);
            }else{
                left++;
            }
        }
        return nums.size();
    }
};



class speedIndicator_solution{
    int removeElement(vector<int> &nums, int val){
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < (int)nums.size() ; ++fastIndex){
            if(nums[fastIndex] != val){
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }  
};

int main()
{
    vector<int> nums = {3,2,2,3};
    int val = 3;
    my_Solution slt;
    cout <<  slt.removeElement(nums,val) << endl;
}

