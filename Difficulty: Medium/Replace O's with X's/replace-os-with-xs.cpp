//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void changeState(int i,int j,int n, int m, vector<vector<int>>&state, vector<vector<char>>&mat){
        if (i>=n || j>=m || i<0 || j<0 || mat[i][j] == 'X' || state[i][j]==1) return;
        state[i][j] = 1;
        changeState(i+1,j,n, m,state,mat);
        changeState(i-1,j,n, m,state,mat);
        changeState(i,j+1,n, m,state,mat);
        changeState(i,j-1,n, m,state,mat);
    }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> state(n, vector<int> (m, 0));
        for (int i=0; i<n; i++){
            if (mat[i][0] == 'O') changeState(i,0,n,m,state,mat);
            if (mat[i][m-1] == 'O') changeState(i,m-1,n,m,state,mat);
        }
        for (int j=0; j<m; j++){
            if (mat[0][j] == 'O') changeState(0,j,n,m,state,mat);
            if (mat[n-1][j] == 'O') changeState(n-1,j,n,m,state,mat);
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat[i][j] == 'O'){
                    if (state[i][j] == 1)continue;
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends