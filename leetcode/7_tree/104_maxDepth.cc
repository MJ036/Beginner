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
//层序遍历求最大深度
    int maxDepth(TreeNode* root) {
//        vector<vector<int>> result; 层序遍历
        int dep = 0;
        queue<TreeNode*> que;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
//            vector<int> vec;
            int size = que.size();
            for(int i = 0; i  < size; i++){
                TreeNode* cur = que.front();
                que.pop();
//                vec.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            dep++;
//            result.push_back(vec);
        }
        return dep;
    }

//后序遍历（高度）解法
    int getdepth(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int left_depth = getdepth(node->left);
        int right_depth = getdepth(node->right);
        int depth =  1 + max(left_depth,right_depth);
        return depth;
    }
    int maxDepth_recursive(TreeNode* root){
        return getdepth(root);
    }

};

//前序遍历、深度解法;
class SolutionB{
public:
    int result;
    void getdepth(TreeNode* node, int depth){
        result = result > depth ? result : depth;
        if(node->left == NULL && node->right == NULL) return;
        if(node->left){
            depth++;
            getdepth(node->left,depth);
            depth--;
        }
        if(node->right){
            depth++;
            getdepth(node->right,depth);
            depth--;
        }
        return;


    }
    int maxDepth(TreeNode* root){
        result = 0;
        if(root == nullptr){
            return result;
        }
        getdepth(root,1);
        return result;
    }

};
