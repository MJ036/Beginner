#include "mai.h"
#include <cstdlib>
using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int result = 0;
        size_t size = arr.size();
        for(int i = 0; i < size; ++i){
            for(int j = i + 1; j < size; ++j){
                if(abs(arr[i] - arr[j]) <= a){
                    for(int k = j + 1; k < size; ++k){
                        if(abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c){
                            result++;
                        }
                    }
                }
            }
        }
        return result;
    }
};
