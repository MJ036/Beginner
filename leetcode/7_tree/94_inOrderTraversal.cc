#include "mai.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归
class Solution
{
public:
    void inOrder(TreeNode *cur, vector<int> &result)
    {
        if (cur == nullptr)
            return;
        inOrder(cur->left, result);
        result.push_back(cur->val);
        inOrder(cur->right, result);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        inOrder(root, vec);
        return vec;
    }
};

// 迭代
class Solution1
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur != nullptr || !st.empty())
        {
            if (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};

//统一格式
class Solution2
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
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
                st.push(cur);
                st.push(nullptr);
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
