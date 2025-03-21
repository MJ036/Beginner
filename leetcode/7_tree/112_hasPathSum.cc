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
private:
    bool traversal(TreeNode* cur, int count){
        if(!cur->left && !cur->right && count == 0) return true;
        if(!cur->left && !cur->right) return false;

        if(cur->left){
            if(traversal(cur->left, count - cur->left->val)) return true;
        }
        if(cur->right){
            if(traversal(cur->right, count - cur->right->val)) return true;
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return traversal(root,targetSum - root->val);
    }
};

