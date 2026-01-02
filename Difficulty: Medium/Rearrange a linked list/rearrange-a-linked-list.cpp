/* Node structure

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    void rearrangeEvenOdd(Node *head) {
        Node *temp = head;
        Node *ans = new Node(-1);
        Node *tmp = ans;
        int n = 1;
        while(temp != NULL) {
            if(n % 2 == 1) {
                tmp->next = new Node(temp->data);
                tmp = tmp->next;
            }
            temp = temp->next;
            n++;
        }
        Node *temp1 = head;
        n = 1;
        while(temp1 != NULL) {
            if(n % 2 == 0) {
                tmp->next = new Node(temp1->data);
                tmp = tmp->next;
            }
            temp1 = temp1->next;
            n++;
        }
        ans = ans->next;
        while(ans != NULL) {
            head->data = ans->data;
            head = head->next;
            ans = ans->next;
        }
    }
};