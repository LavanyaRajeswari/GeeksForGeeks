//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void rec(vector<vector<char>>& mat,int i,int j,int n,int m) {
        if(i >= n || j >= m || i < 0 || j < 0 || mat[i][j] != 'O') {
            return;
        }
        mat[i][j] = '$';
        rec(mat,i+1,j,n,m);
        rec(mat,i-1,j,n,m);
        rec(mat,i,j+1,n,m);
        rec(mat,i,j-1,n,m);
    }
    
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int n = mat.size(),m = mat[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 'O' and i == 0 || j == 0 || i == n-1 || j == m-1) {
                    rec(mat,i,j,n,m);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
                if(mat[i][j] == '$') {
                    mat[i][j] = 'O';
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