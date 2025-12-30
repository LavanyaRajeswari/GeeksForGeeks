/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* addTwoLists(Node* l1, Node* l2) {
        Node* root = new Node(-1);
        Node* temp = root;
        int carry = 0;
        vector<int>v1;
        vector<int>v2;
        while(l1 != NULL){
           v1.push_back(l1->data);
           l1 = l1->next;
        }
        while(l2 != NULL){
           v2.push_back(l2->data);
           l2 = l2->next;
        }
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        int n = v1.size(), m = v2.size();
        int i = 0, j = 0;
        vector<int>ans;
        while(i < n and j < m) {
            int c = v1[i]+v2[j]+carry;
            if(c > 9) {
                c %= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            ans.push_back(c);
            i++;
            j++;
        }
        while(i < n) {
            int c = v1[i]+carry;
            if(c > 9) {
                c %= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            ans.push_back(c);
            i++;
        }
        while(j < m) {
            int c = v2[j]+carry;
            if(c > 9) {
                c %= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            ans.push_back(c);
            j++;
        }
        if(carry == 1) ans.push_back(1);
        reverse(ans.begin(),ans.end());
        int f = 0;
        for(int i = 0; i < ans.size() ; i++) {
            if(f == 0 and ans[i] == 0) {
                ans[i] = -1;
            }
            else {
                f = 1;
            }
        }
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] != -1){
           temp->next = new Node(ans[i]);
           temp = temp->next;
            }
        }
        return root->next;
    }
};