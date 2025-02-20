//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        stack<int>st;
        for(int i =0; i < s.length(); i++) {
            if(!st.empty() and ((st.top() == '(' and s[i] == ')') || (st.top() == '[' and s[i] == ']') || (st.top() == '{' and s[i] == '}'))) {
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return (st.empty()) ? true : false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends