#include "mai.h"
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* traversal(vector<int>& nums,int beg,int end){
        //终止条件
        if(beg == end) return nullptr;

        //获取最大值
        int max_val =nums[beg];
        int idx_max =beg;
        for(int idx = beg;idx < end; idx++){
            if(nums[idx] > max_val){
                max_val = nums[idx];
                idx_max = idx;
            }
        }

        auto root = new TreeNode(max_val);

        //划分数组 左闭右开
        root->left = traversal(nums,beg,idx_max);
        root->right = traversal(nums,idx_max + 1,end);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums,0,nums.size());
    }
};
