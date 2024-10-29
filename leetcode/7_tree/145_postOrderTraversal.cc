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

//递归法
class Solution {
public:
    void postOrder(TreeNode* cur, vector<int>& result){
        if(cur == nullptr) return;
        postOrder(cur->left, result);
        postOrder(cur->right, result);
        result.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        postOrder(root, vec);
        return vec;
    }
};

//迭代法
class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur;
        if(root == nullptr) return result;
        st.push(root);
        while(!st.empty()){
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

//统一格式
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
                st.push(cur);
                st.push(nullptr);
                if (cur->right)
                    st.push(cur->right);
                if (cur->left)
                    st.push(cur->left);
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

 