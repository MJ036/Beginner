#include "mai.h"

using namespace std;

//Definition for a  Node.
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

class Solution {
public:
    int maxDepth(Node* root) {
        int dep = 0;
        queue<Node*> que;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            while(size > 0){
                Node* cur = que.front();
                que.pop();
                for(auto num : cur->children){
                    que.push(num);
                }
                size--;
            }
            dep++;
        }
        return dep;
    }
};
