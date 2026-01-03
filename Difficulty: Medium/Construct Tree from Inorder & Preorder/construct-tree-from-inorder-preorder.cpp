/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int i = 0;
    Node* bulid(int a,int b,vector<int>&preorder,map<int,int>&mp) {
        if(a > b) return nullptr;
        Node* root = new Node(preorder[i]);
        int ind = mp[preorder[i]];
        i++;
        root->left = bulid(a,ind-1,preorder,mp);
        root->right = bulid(ind+1,b,preorder,mp);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = preorder.size();
        map<int,int>mp;
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return bulid(0,n-1,preorder,mp);
    }
};