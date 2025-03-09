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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 0;

        int leftValue = sumOfLeftLeaves(root->left);
        if(root->left && root->left->left == nullptr && root->left->right == nullptr){
            leftValue = root->left->val;
        }
        
        int rightValue = sumOfLeftLeaves(root->right);
        return leftValue + rightValue;
    }

};
