//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int rec(string &s1,string &s2,int i,int j,int n,int m,vector<vector<int>>&dp) {
        if(i >= n || j >= m){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) {
            dp[i][j] = 1+rec(s1,s2,i+1,j+1,n,m,dp);
        }
        else{
            int x = rec(s1,s2,i+1,j,n,m,dp);
            int y =rec(s1,s2,i,j+1,n,m,dp);
            dp[i][j] = max(x,y);
        }
        return dp[i][j];
        
    }
    int longestPalinSubseq(string &s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return rec(s,s2,0,0,n,n,dp);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends