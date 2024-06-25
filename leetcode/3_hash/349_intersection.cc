#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;



class Solution_b{
public:
    vector<int> intersection(vector<int>& nums1,vector<int>& nums2){
        unordered_set<int> result;
        int hash[1005] = {0};
        for(auto num : nums1){
            hash[num] = 1;
        }
        for(auto num : nums2){
            if(hash[num] == 1){
                result.insert(num);
            }
        }
        return vector<int>(result.begin(),result.end());
    }
};




























class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums1_set(nums1.begin(),nums1.end());
        for(auto num : nums2){
            if(nums1_set.find(num) != nums1_set.end()){
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(),result_set.end());
        
    }

};

int main()
{
    
}

