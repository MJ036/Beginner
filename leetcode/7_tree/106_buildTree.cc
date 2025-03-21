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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
                //判断后序遍历序列是否为空
                if(postorder.size() == 0) return nullptr;

                //取出根节点
                int root_val = postorder.back();
                auto root = new TreeNode(root_val);
        
                //如果后序序列空了，直接返回根节点
                if(postorder.size() == 1) return root;
                //没空，移除处理过的根节点
                postorder.pop_back();
        
                //找到分割点
                size_t split;
                for(split = 0; split < inorder.size(); ++split){
                    if(inorder[split] == root_val) break;
                }
        
                //拆分中序序列 [0,split),[split+1 ,end)
                vector<int> inorderLeft(inorder.begin(),inorder.begin() + split);
                vector<int> inorderRight(inorder.begin() + split + 1, inorder.end());
                //拆分后序，因为拆分后的中序和后序序列中元素数量相同，后序直接按照中序数量分割
                vector<int> postorderLeft(postorder.begin(),postorder.begin() + inorderLeft.size());
                vector<int> postorderRight(postorder.begin() + inorderLeft.size(),postorder.end());
        
                
                //处理左半
                auto leftNode = traversal(inorderLeft,postorderLeft);
                //处理右半
                auto rightNode = traversal(inorderRight,postorderRight);
                
                root->left = leftNode;
                root->right = rightNode;
                return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder, postorder);
    }
};
