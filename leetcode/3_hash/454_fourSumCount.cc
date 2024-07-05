#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> umap;
        for(int A : nums1){
            for(int B : nums2){
                umap[A + B]++;
            }
        }
        int count = 0;
        for(int C : nums3){
            for(int D: nums4){
                if(umap.find(0 - (C + D)) != umap.end()){
                    count+= umap[0 - (C + D)];
                }
            }
        }
        return count;
    }

    int fourSumCount2(vector<int>& num1,vector<int>& num2, vector<int>& num3, vector<int>& num4){
        unordered_map<int,int> umap;
        int count = 0;
        for(auto a : num1){
            for(auto b: num2){
                umap[a+b]++;
            }
        }
        for(auto c : num3){
            for(auto d : num4){
                if(umap.find(0 - (c + d)) != umap.end()){
                    count += umap[0-(c+d)];
                }
            }
        }
        return count;
    }



};













 

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

