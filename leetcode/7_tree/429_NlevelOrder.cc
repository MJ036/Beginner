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


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//层序遍历的递归方法
class Solution {
public:
    void order(Node* cur, vector<vector<int>> &result, size_t depth){
        if(cur == nullptr) return;
        if(result.size() == depth) result.push_back(vector<int>()); //若第一次访问该层，则创建vector
        result[depth].push_back(cur->val);
        for(auto num : cur->children){
            order(num,result,depth+1);
        }
    }

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        int depth = 0;
        order(root,result,depth);
        return result;
    }
};
