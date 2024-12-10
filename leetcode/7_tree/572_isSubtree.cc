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
private:
bool compare(TreeNode* p, TreeNode* q){
    if(p == nullptr && q != nullptr){
        return false;
    }else if(p != nullptr && q == nullptr){
        return false;
    }else if(p == nullptr && q == nullptr){
        return true;
    }else if(p->val != q->val){
        return false;
    }
    

    bool leftside = compare(p->left,q->left);
    bool rightside = compare(p->right,q->right);
    return leftside && rightside;
}

bool dfs(TreeNode* p, TreeNode* q){
    if(p == nullptr){
        return false;
    }
    return compare(p,q) || dfs(p->left,q) || dfs(p->right,q);
}

public:
    bool isSubTree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root,subRoot);
    }
};
