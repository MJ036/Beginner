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
    //返回根节点
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }else{
            if(!root->left){
                root = root->right;
            }else if(!root->right){
                root = root->left;
            }else{      //若待删除节点的左右孩子都不空，就让把左子树嫁接到右子树的最左下节点
                auto node = root->right;
                while(node->left){
                    node = node->left;
                }
                node->left = root->left;
                root = root->right;
            }
        }
        return root;
    }
};
