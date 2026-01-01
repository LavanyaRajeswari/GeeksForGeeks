/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
        Node* temp = head;
        int cur = -1;
        Node* prev = head;
        while(temp != NULL) {
            if(cur == temp->data) {
                temp = prev;
                temp->next = temp->next->next;
            }
            if(cur != temp->data) {
                cur = temp->data;
                prev = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};