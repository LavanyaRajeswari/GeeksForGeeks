//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    long long rec(long long n,vector<long long>&dp){
        if(n < 1) {
            return dp[n] = 0;
        }
        if(n == 1) {
            return dp[n] = 1;
        }
        if(dp[n] != -1) return dp[n];
        return dp[n] = rec(n-1,dp)+rec(n-2,dp);
    }
    
    int countStrings(int n) {
        vector<long long>dp(n+2,-1);    
        rec(n+1,dp);
        long long ans = dp[n]+dp[n+1];
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.countStrings(n);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends