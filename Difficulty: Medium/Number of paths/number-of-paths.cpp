//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int start(int i,int j,int n,int m,vector<vector<int>>&dp){
        if (i==n || j==m) return 0;
        if (i==n-1 && j==m-1) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        int right = start(i, j+1, n, m, dp);
        int down = start(i+1, j, n, m, dp);
        dp[i][j] = right+down;
        return dp[i][j];
    }
    int numberOfPaths(int n, int m) {
        // Code Here
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return start(0,0,n,m, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.numberOfPaths(arr[0], arr[1]) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends