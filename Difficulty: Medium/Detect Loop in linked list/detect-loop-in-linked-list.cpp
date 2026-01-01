/*
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} */

class Solution {
  public:
    bool detectLoop(Node* head) {
        if(head == NULL) return false;
        Node* slow = head;
        Node* fast = head;   
    while(fast !=NULL and fast->next!=NULL ){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) return true;
    }
    return false;
    }
};