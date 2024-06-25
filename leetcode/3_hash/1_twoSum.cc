#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> result;
        for(int i = 0 ; i < (int)nums.size() ; i++){
            auto it = result.find(target - nums[i]);
            if(it == result.end()){
                result.insert(pair<int,int>(nums[i],i));
            }else{
                return {it->second,i};
            }
        }
        return {};
    }
};
 

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

