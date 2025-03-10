//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rec(string &s1, string &s2, int i, int j, int n, int m, vector<vector<int>>&dp) {
        if(i >= n and j >= m) {
            return 0;
        }
        if(i >= n) {
            return (m-j);
        }
        if(j >= m) {
            return (n-i);
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) {
            return dp[i][j] = rec(s1,s2,i+1,j+1,n,m,dp);
        }
        int x = rec(s1,s2,i+1,j,n,m,dp);
        int y = rec(s1,s2,i+1,j+1,n,m,dp);
        int z = rec(s1,s2,i,j+1,n,m,dp);
        dp[i][j] = 1+min({x,y,z});
        return dp[i][j];
    }
    int editDistance(string& s1, string& s2) {
        int n = s1.length(),m = s2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return rec(s1,s2,0,0,n,m,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends