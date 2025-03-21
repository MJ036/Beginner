#include "mai.h"
#include <cstddef>
#include <ios>
#include <iterator>
#include <vector>
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
    TreeNode* traversal(vector<int>& inorder,int inorderBegin, int inorderEnd, vector<int>& preorder,int preorderBegin, int preorderEnd){
                //判断前序遍历序列是否为空
                if(preorderBegin == preorderEnd) return nullptr;

                //取出根节点
                int root_val = preorder[preorderBegin];
                auto root = new TreeNode(root_val);
        
                //如果前序序列只有一个节点，直接返回根节点
                if(preorderEnd - preorderBegin == 1) return root;
        

                //找到分割点
                size_t split;
                for(split = inorderBegin; split < inorderEnd; ++split){
                    if(inorder[split] == root_val) break;
                }
        
                //左闭右开
                //拆分中序序列
                int leftInorderBegin = inorderBegin;
                int leftInorderEnd = split;
                int rightInorderBegin = split + 1;
                int rightInorderEnd = inorderEnd;
                //拆分前序
                int leftPreorderBegin = preorderBegin + 1;
                int leftPreorderEnd = preorderBegin + 1 + (split - inorderBegin );
                int rightPreorderBegin =preorderBegin +  1 + (split - inorderBegin);
                int rightPreorderEnd = preorderEnd;
        
                
                //处理左半
                root->left = traversal(inorder,leftInorderBegin,leftInorderEnd,preorder,leftPreorderBegin,leftPreorderEnd);
                //处理右半
                root->right= traversal(inorder,rightInorderBegin,rightInorderEnd,preorder,rightPreorderBegin,rightPreorderEnd);
             
                return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0 || preorder.size() == 0) return NULL;
        return traversal(inorder,0,inorder.size(), preorder,0,preorder.size());
    }
};
