/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
class Solution {
  public:
    Node* sortedMerge(Node* list1, Node* list2) {
         if(list1 == NULL and list2 == NULL) return NULL;
        if(list1 != NULL and list2 == NULL) return list1;
        if(list1 == NULL and list2 != NULL) return list2;
        Node* newList = new Node(min(list1->data,list2->data));
        Node* temp = newList;
        if(list1->data < list2->data) {
            list1 = list1->next;
        }
        else{
            list2 = list2->next;
        }
        while(list1 != NULL and list2 != NULL) {
            if(list1->data <= list2->data) {
                temp->next = new Node(list1->data);
                temp = temp->next;
                list1 = list1->next;
            }
            else{
                temp->next = new Node(list2->data);
                temp = temp->next;
                list2 = list2->next;
            }
        }
        while(list1 != NULL) {
            temp->next = new Node(list1->data);
            temp = temp->next;
            list1 = list1->next;
        }
        while(list2 != NULL) {
            temp->next = new Node(list2->data);
            temp = temp->next;
            list2 = list2->next;
        }
        return newList;
    }
};