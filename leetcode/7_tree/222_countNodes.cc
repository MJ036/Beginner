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
    int countNodes(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left_depth = 0;
        int right_depth = 0;

        TreeNode* left,* right;
        left = root->left;
        right = root->right;

        while(left){
            left = left->left;
            left_depth++;
        }
        while(right){
            right = right->right;
            right_depth++;
        }
        if(left_depth == right_depth){
            return (2 << left_depth) - 1;
        }

        int left_count = countNodes(root->left);
        int right_count = countNodes(root->right);
        return left_count + right_count + 1;
        
    }

    int review(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        //记录高度
        int leftNum = 0;
        int rightNum = 0;

        TreeNode* left, *right;
        left = root->left;
        right = root->right;
        while(left){
            left = left->left;
            leftNum++;
        }
        while(right){
            right = right->right;
            rightNum++;
        }
        if(leftNum == rightNum){
           return (2 << leftNum) - 1;
        }
        return review(root->left) + review(root->right) + 1;
    }
};

