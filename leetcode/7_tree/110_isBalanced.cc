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
    int getHight(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        int leftHight = getHight(node->left);
        if(leftHight == -1) return -1;
        int rightHight = getHight(node->right);
        if(rightHight == -1) return -1;
        
        if(abs(leftHight - rightHight) > 1){
            return -1;
        }else{
            return max(leftHight,rightHight) + 1;
        }
    }
    bool isBalanced(TreeNode* root){
        return getHight(root) == -1 ? false : true;
        

    }

};

