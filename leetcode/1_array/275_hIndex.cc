#include "mai.h"

using namespace std;

class Solution{
public:
    int hIndex(vector<int>& citations){
        int n = citations.size();
        int left =0, right = n - 1;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            if(citations[mid] >= n - mid){
                    right = mid - 1;
            }else{
                left = mid + 1;
            }
        }//right > left
        return n - left;
    }
    
    int hIndex2(vector<int>& citations){
        int n = citations.size();
        int left =0, right = n - 1;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            int cmp = citations[mid] - ( n - mid);
            if(cmp < 0){
                left = mid + 1;
            }else{
                if(mid == left || (citations[mid - 1] < (n - mid + 1))){
                    return mid;
                }
                right = mid - 1;
            }
        }
        return 0;
    }
};

int main()
{
    vector<int> vec = {0,1,3,5,6};
    Solution so;
    cout << so.hIndex(vec);
    return 0;
}

