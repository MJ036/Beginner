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

//递归
class Solution {
public:
    void preOrder(TreeNode* cur, vector<int>& result){
        if(cur == nullptr) return;
        result.push_back(cur->val);
        preOrder(cur->left, result);
        preOrder(cur->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        preOrder(root, vec);
        return vec;
    }
};

//迭代
class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur;
        if(root == nullptr) return result;
        st.push(root);
        while(!st.empty()){
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }
        return result;
    }
};

//统一格式
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> st;
        if (root != nullptr)
            st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            if (cur != nullptr)
            {
                st.pop();
                if (cur->right)
                    st.push(cur->right);
                if (cur->left)
                    st.push(cur->left);
                st.push(cur);
                st.push(nullptr);
            }
            else
            {
                st.pop();
                cur = st.top();
                result.push_back(cur->val);
                st.pop();
            }
        }
        return result;
    }
};