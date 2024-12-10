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
    int minDepth(TreeNode* root) {
        vector<vector<int>> result;
        int dep = 0;
        queue<TreeNode*> que;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            vector<int> vec;
            int size = que.size();
            dep++;
            for(int i = 0; i  < size; i++){
                TreeNode* cur = que.front();
                que.pop();
                vec.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
                if(!(cur->left || cur->right)) return dep;
            }
            result.push_back(vec);
        }
        return dep;
    }
    
    int getdepth(TreeNode* node){
        if(node == nullptr){
            return 0;
        } 
        int left_depth = getdepth(node->left);
        int right_depth = getdepth(node->right);
        if(node->left ==nullptr && node->right != nullptr){
            return 1 + right_depth;
        }
        if(node->left !=nullptr && node->right == nullptr){
            return 1 + left_depth;
        }
        int depth =  1 + min(left_depth,right_depth);
        return depth;
    }

    int minDepth_recursive(TreeNode* root){
        return  getdepth(root);
    }

};
