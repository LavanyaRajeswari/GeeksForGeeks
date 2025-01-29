//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int rec(vector<vector<int>>& grid,int i, int j,int n,int x) {
         if(i >= n || j >= n || i < 0 || j < 0 || grid[i][j] != 1) {
             return 0;
         }
         int count = 1;
         grid[i][j] = x;
         count += rec(grid,i+1,j,n,x);
         count += rec(grid,i-1,j,n,x);
         count += rec(grid,i,j+1,n,x);
         count += rec(grid,i,j-1,n,x);
         return count;
    }
    
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return 1;
        map<int,int>mp;
        int x = 2,ans = 0;
        for(int i = 0 ;i < n; i++) {
            for(int j = 0; j < n ; j++) {
                if(grid[i][j] == 1) {
                    mp[x] = rec(grid,i,j,n,x);
                    x++;
                }
            }
        }
        ans = mp[x-1];
        for(int i = 0 ;i < n; i++) {
            for(int j = 0; j < n ; j++) {
                if(grid[i][j] == 0) {
                    map<int,int>st;
                    int cur = 1; 
                    if(i > 0 and grid[i-1][j] != 0) {
                        if(st[grid[i-1][j]] <= 0){
                            st[grid[i-1][j]];
                        }
                    }
                    if(j > 0 and grid[i][j-1] != 0) {
                        if(st[grid[i][j-1]] <= 0){
                            st[grid[i][j-1]];
                        }
                    }
                    if(i < (n-1) and grid[i+1][j] != 0) {
                        if(st[grid[i+1][j]] <= 0){
                            st[grid[i+1][j]];
                        }
                    }
                    if(j < (n-1) and grid[i][j+1] != 0) {
                        if(st[grid[i][j+1]] <= 0){
                            st[grid[i][j+1]];
                        }
                    }
                    for(auto it : st) {
                        cur += mp[it.first];
                    }
                    ans = max(ans,cur);
                }
            }
        }
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
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends