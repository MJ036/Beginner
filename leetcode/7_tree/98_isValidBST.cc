#include "mai.h"
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
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
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;

        auto left = isValidBST(root->left);
        if(pre != nullptr && pre->val >= root->val){
            return false;
        }
        pre = root;
        auto right = isValidBST(root->right);
        return left && right;
    }
};
