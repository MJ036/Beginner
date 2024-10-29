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

//层序遍历的递归方法
class Solution {
public:
    void order(TreeNode* cur, vector<vector<int>> &result, size_t depth){
        if(cur == nullptr) return;
        if(result.size() == depth) result.push_back(vector<int>()); //若第一次访问该层，则创建vector
        result[depth].push_back(cur->val);
        order(cur->left,result,depth+1);
        order(cur->right,result,depth+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        order(root,result,depth);
        return result;
    }
};

//迭代法
class Solution1{
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            vector<int> vec;
            int size = que.size();
            for(int i = 0; i  < size; i++){
                TreeNode* cur = que.front();
                que.pop();
                vec.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};

//复习二叉树层次遍历：递归法和迭代法
class Review{
    void order(TreeNode* cur, vector<vector<int>> &result, int depth){
        if(cur == nullptr) return;
        if(result.size() == depth) result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        order(cur->left,result,depth+1);
        order(cur->right,result,depth+1);
    }
    vector<vector<int>> levelOrder_rec(TreeNode* root){
        vector<vector<int>> result;
        int depth = 0;
        order(root,result,depth);
        return result;
    }
    
    //迭代
    vector<vector<int>> levelOrder_it(TreeNode* root){
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if(root != nullptr) que.push(root);
        int size = 0;
        while(!que.empty()){
            vector<int> vec;
            TreeNode* cur = que.front();
            que.pop();
            size = que.size();
            while(size--){
                vec.push_back(cur->val);
            }
            result.push_back(vec);
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        return result;
    }

};


//复习迭代
class Review1_1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            while(size--){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};


