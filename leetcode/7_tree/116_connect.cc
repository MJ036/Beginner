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

struct Node{
    int val;
    Node *left;
    Node *right;
    Node *next;
};

//层序遍历的递归方法
class Solution {
public:
    Node* connect(Node* root){
        vector<vector<int>> result;
        queue<Node*> que;
        if(root != nullptr) que.push(root);
        Node* pre = nullptr;
        Node* cur = nullptr;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                if(i == 0){
                    pre = que.front();
                    que.pop();
                    cur = pre;
                }
                else{
                    cur = que.front();
                    pre->next = cur;
                    pre = cur;
                    que.pop();
                }
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            cur->next = nullptr;
        }
        return root;
    }
};
