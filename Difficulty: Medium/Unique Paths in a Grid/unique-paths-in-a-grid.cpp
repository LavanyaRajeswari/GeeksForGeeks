class Solution {
  public:
  
    long long rec(int m,int n ,int i, int j, vector<vector<long long>>&dp,vector<vector<int>>Grid) {
        if(i >= m || j >= n) return 0;
        if(Grid[i][j] == 1) {
            dp[i][j] = 0;
            return 0;
        }
        if(i+1 == m and j+1 == n) {
            dp[i][j] = 1;
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        long long right = rec(m,n,i,j+1,dp,Grid);
        long long down = rec(m,n,i+1,j,dp,Grid);
        dp[i][j] = down+right;
        return dp[i][j];
    }
    
    int uniquePaths(vector<vector<int>> &grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,-1));
        rec(m,n,0,0,dp,grid);
        return dp[0][0];
    }
};