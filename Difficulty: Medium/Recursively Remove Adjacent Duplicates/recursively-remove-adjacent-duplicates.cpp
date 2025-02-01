//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    string removeUtil(string &s) {
        while (true){
            int n = s.size();
            if (n <= 1) break;
            int i = 0,j = 0;
            string newS = "";
            while (i<n){
                j = i;
                while (j<n && s[j]==s[i])j++;
                if ((j-i)==1) newS += s[i];
                i = j;
            }
            if (s == newS) break;
            s = newS;
        }
        return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        s = ob.removeUtil(s);
        if (s.size() == 0)
            cout << "\"\"";
        else
            cout << s << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends