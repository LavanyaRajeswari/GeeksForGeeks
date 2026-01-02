/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    void rec(Node *ch, vector<int>&v) {
        while(ch != NULL) {
            v.push_back(ch->data);
            if(ch->bottom != NULL) {
                rec(ch->bottom,v);
            }
            ch = ch->next;
        }
    }
    Node *flatten(Node *head) {
         Node* ans = new Node(-1);
        Node* temp = ans;
        vector<int>v;
        while(head != NULL) {
            v.push_back(head->data);
            if(head->bottom != NULL) {
                rec(head->bottom,v);
            }
            head = head->next;
        }
        sort(v.begin(),v.end());
        for(auto it:v) {
                temp->bottom = new Node(it);
                temp = temp->bottom;
        }
        ans = ans->bottom;
        return ans;
    }
};