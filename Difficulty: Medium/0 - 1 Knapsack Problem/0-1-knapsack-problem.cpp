//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int rec(vector<int> &wt, vector<int> &val, int cap,int i, int n,vector<vector<int>>&dp) {
        if(i >= n) {
            return 0;
        }
        if(dp[i][cap] != -1) return dp[i][cap];
        int l = 0, r = 0;
        if(wt[i] <= cap) {
            l = val[i] + rec(wt,val,cap-wt[i],i+1,n,dp);
        }
        r = rec(wt,val,cap,i+1,n,dp);
        return dp[i][cap] = max(l,r);
    }
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1, -1));
        int ans = rec(wt,val,capacity,0,n,dp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends