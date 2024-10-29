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
    int maxDepth(TreeNode* root) {
        vector<vector<int>> result;
        int dep = 0;
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
            dep++;
            result.push_back(vec);
        }
        return dep;
    }
};
