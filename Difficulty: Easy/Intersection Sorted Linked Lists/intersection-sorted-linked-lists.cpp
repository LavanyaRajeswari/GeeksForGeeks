class Solution {
public:
    Node *findIntersection(Node *head1, Node *head2) {
        Node *ans = new Node(-1);
        Node *temp = ans;
        map<int,int>mp;
        while(head1 != NULL) {
            mp[head1->data]++;
            head1 = head1->next;
        }
        while(head2 != NULL) {
            if(mp.find(head2->data) != mp.end())  {
                temp->next = new Node(head2->data);
                temp = temp->next;
            }
            head2 = head2->next;
        }
        return ans->next;
    }
};