//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool rec(vector<int>&arr,int sum,int i,int n,int cur,vector<vector<int>>&dp) {
        if(i > n || cur > sum) return false;
        if(i == n and cur == sum) return true;
        else if(i == n and cur != sum) return false;
        if(dp[i][cur] != -1) return dp[i][cur];
        bool x = rec(arr,sum,i+1,n,cur+arr[i],dp);
        bool y = rec(arr,sum,i+1,n,cur,dp);
        return dp[i][cur] = (x||y) ? 1 : 0;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return rec(arr,sum,0,n,0,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends