//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++


class Solution
{
public:
    struct TrieNode{
        bool isLeaf;
        TrieNode* children[26];
        bool prefix;
        TrieNode() {
            isLeaf = false;
            prefix = false;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };
    string longestString(vector<string> &words)
    {
        sort(words.begin(),words.end());
        TrieNode* head = new TrieNode();
        TrieNode* temp = head;
        int l = 0;
        string res = "";
        for(int i = 0; i < words.size(); i++) {
            temp = head;
            int cl = 0;
            // cout<<words[i]<<" ";
            for(auto c : words[i]) {
                if(temp->children[c-'a'] == NULL) {
                    temp->children[c-'a'] = new TrieNode();
                }
                temp = temp->children[c-'a'];
                if(temp->isLeaf) cl++;
            }
            cl++;
            temp->isLeaf = true;
            if(l < words[i].size() and cl == words[i].size()) {
                l = words[i].size();
                res = words[i];
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends