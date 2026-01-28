/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    /*You are required to complete this method*/
    int rec(Node* root, int l) {
        if(root == NULL) return l;
        int ans = 0;
        ans = max(rec(root->left,l+1),rec(root->right,l+1));
        return ans;
    }
    int maxDepth(Node *root) {
        if(root == NULL) return 0;
        int l = 0;
        int ans = rec(root,l);
        return ans;
    }
};
