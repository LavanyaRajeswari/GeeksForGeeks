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
    void rec(Node* root,int level,int &ans){
        if(root == NULL){
            ans = max(level,ans);
            return;
        }
        rec(root->left,level+1,ans);
        rec(root->right,level+1,ans);
    }
    int height(Node* root) {
    int ans = 0;
    rec(root,0,ans);
    return ans-1;
    }
};