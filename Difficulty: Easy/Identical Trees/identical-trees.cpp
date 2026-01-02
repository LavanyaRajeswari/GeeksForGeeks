/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    void check(Node* p,Node* q,int &ans){
        if(p == NULL and q == NULL){
            return ;
        }
        if(p == NULL or q == NULL){
            ans = 0;
            return ;
        }
        if(p->data != q->data){
            ans = 0;
        }
        check(p->left,q->left,ans);
        check(p->right,q->right,ans);
    }
    bool isIdentical(Node* p, Node* q) {
        int ans=1;
        check(p,q,ans);
        return ans;
    }
};