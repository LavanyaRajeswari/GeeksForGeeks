//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int ans = 0;
    int rec(int i, int j, int n, int m, vector<vector<int>>&grid) {
        if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 0) {
            // ans = max(ans,count);
            return 0;
        }
        int count = 0;
        if(grid[i][j] == 1){
            count = 1;
            // cout<<i<<" "<<j<<" "<<count<<endl;
            grid[i][j] = 0;
            count += rec(i+1,j,n,m,grid);
            count += rec(i-1,j,n,m,grid);
            count += rec(i+1,j+1,n,m,grid);
            count += rec(i+1,j-1,n,m,grid);
            count += rec(i-1,j+1,n,m,grid);
            count += rec(i-1,j-1,n,m,grid);
            count += rec(i,j+1,n,m,grid);
            count += rec(i,j-1,n,m,grid);
        }
        // grid[i][j] = 1;
        return count;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n ; i++) {
            for(int j = 0; j < m ; j++) {
                if(grid[i][j] == 1) {
                    ans  = max(rec(i,j,n,m,grid),ans);
                }
            }
        }
        // for (int i = 0; i < n ; i++) {
        //     for(int j = 0; j < m ; j++) {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends