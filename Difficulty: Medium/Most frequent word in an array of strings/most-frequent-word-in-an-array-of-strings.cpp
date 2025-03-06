//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++
struct Node{
    int end,fo;
    Node *children[26];
    Node(){
        end = 0;
        fo = -1;
        for (int i=0; i<26; i++){
            children[i] = NULL;
        }
    }
};

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        int maxi = 0,mo = -1;
        string res = "";
        Node *head = new Node();
        for (int i=0; i<n; i++){
            Node *temp = head;
            for (char c : arr[i]){
                if (temp->children[c-'a'] == NULL)
                    temp->children[c-'a'] = new Node();
                temp = temp->children[c-'a'];
            }
            temp->end++;
            if (temp->fo == -1) temp->fo = i;
            if (temp->end > maxi ||(temp->end == maxi && mo < temp->fo)){
                mo = temp->fo;
                maxi = temp->end;
                res = arr[i];
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends