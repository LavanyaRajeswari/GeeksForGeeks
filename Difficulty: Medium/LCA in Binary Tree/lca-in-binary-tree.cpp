/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* rec(Node* root, int n1, int n2) {
        if(!root || n1 == root->data || n2 == root->data) return root;
        Node* left = rec(root->left,n1,n2);
        Node* right = rec(root->right,n1,n2);
        if(left && right) return root;
        return left ? left : right;
    }
    Node* lca(Node* root, int n1, int n2) {
        return rec(root, n1, n2);
    }
};