/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool rec(Node* root,long long &prev) {
        if(!root) return true;
        
        if(!rec(root->left,prev)) return false;
        
        if(prev >= root->data) return false;
        
        prev = root->data;
        
        return rec(root->right,prev);
    }
    bool isBST(Node* root) {
        long long prev = LONG_MIN;
        return rec(root,prev);
    }
};