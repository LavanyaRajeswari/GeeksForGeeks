//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    
    void sort(Node **head)
    {
         Node *temp = *head;
         Node *l1 = NULL;
         Node *t1 = NULL;
         Node *l2 = NULL;
         Node *t2 = NULL;
         int i = 0;
         while(temp!=NULL){
             if(i%2==0){
                if(l1 == NULL){
                    Node *data1 = new Node(temp->data);
                    l1 = data1;
                    t1 = l1;
                } 
                else{
                    Node *data1 = new Node(temp->data);
                    t1->next = data1;
                    t1 = data1;
                }
             }
             else{
                 if(l2 == NULL){
                    Node *data2 = new Node(temp->data);
                    l2 = data2;
                    t2 = l2;
                } 
                else{
                    Node *data2 = new Node(temp->data);
                    t2->next = data2;
                    t2 = data2;
                }
             }
             i++;
             temp = temp->next;
         }
         Node *prev = NULL;
         while(l2!=NULL){
             if(prev == NULL){
                 Node *x = new Node(l2->data);
                 prev = x;
             }
             else{
                 Node *x = new Node(l2->data);
                 x->next = prev;
                 prev = x;
             }
             l2 = l2->next;
         }
         t1->next = prev;
         *head = l1;
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends