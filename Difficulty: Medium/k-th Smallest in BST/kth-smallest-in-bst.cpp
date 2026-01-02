/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    void rec(Node* root,vector<int>&v){
        if(root == NULL) return;
        v.push_back(root->data);
        rec(root->left,v);
        rec(root->right,v);
    }
    int kthSmallest(Node* root, int k) {
        vector<int>v;
        rec(root,v);
        sort(v.begin(),v.end());
        if(k > v.size()) return -1;
        return v[k-1];
    }
};