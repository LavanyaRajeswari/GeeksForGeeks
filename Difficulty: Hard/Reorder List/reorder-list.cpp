/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    void reorderList(Node* head) {
        int n = 1;
        Node* c = head;
        Node* temp = head;
        Node* prev = new Node(temp->data);
        while(c->next!=NULL){
            c = c->next;
            n++;
        }    
        temp= temp->next;
        while(temp!=NULL){
                Node* d = new  Node(temp->data);
                d->next = prev;
                prev = d;
                temp = temp->next;
        }
         Node* tmp = head;
         temp = head; 
         int k = n;
        while(n){
            Node* dum1 = tmp->next;
            Node* dum2 = prev->next;
            tmp->next = prev;
            prev->next = dum1;
            prev = dum2;
            tmp = dum1;
            n--;
        }
        while(k-1){
            temp = temp->next;
            k--;
        }
        temp->next = NULL;
    }
};