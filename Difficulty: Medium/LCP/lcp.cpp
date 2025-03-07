//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    struct TrieNode{
        bool isLeaf;
        int count;
        TrieNode* children[26];
        TrieNode(){
            count = 0;
            isLeaf = false;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };
    string LCP(string ar[], int n)
    {
        TrieNode* root = new TrieNode();
        TrieNode* temp = root;
        for(int i = 0; i < n; i++) {
            temp = root;
            for(auto it:ar[i]) {
                if(temp->children[it-'a'] == NULL) {
                    temp->children[it-'a'] = new TrieNode();
                }
                temp = temp->children[it-'a'];
                temp->count++;
            }
            temp->isLeaf = true;
        }
        string ans = "";
        temp = root;
        for(auto it : ar[0]) {
            if(temp->children[it-'a'] != NULL) {
                temp = temp->children[it-'a'];
            }
            if(temp->count == n){
                ans += it;
            }
            else{
                break;
            }
        }
        if(ans == "") return "-1";
        return ans;
    }
};


//{ Driver Code Starts.

int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends