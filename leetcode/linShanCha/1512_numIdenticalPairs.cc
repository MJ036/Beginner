#include "mai.h"
#include <type_traits>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        for(auto beg = nums.begin(),end = nums.end(); beg != end; ++beg){
            for(auto beg1 = beg+1; beg1 != end; ++beg1){
                if(*beg == *beg1){
                    result++;
                }
            }
        }
        return result;
    }
};
