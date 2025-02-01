//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // bool ans = false;
    bool Poss(string &word, int i, int j, int n, int m,int ind,vector<vector<char>>&mat) {
        if(ind == word.length()) {
            return true;
        }
        if(i >= n || j >= m || i < 0 || j < 0) {
            return false;
        }
        if(word[ind] == mat[i][j]) {
            char x = mat[i][j];
            mat[i][j] = '1';
            bool ans = (Poss(word,i+1,j,n,m,ind+1,mat) || Poss(word,i-1,j,n,m,ind+1,mat) || Poss(word,i,j+1,n,m,ind+1,mat) || Poss(word,i,j-1,n,m,ind+1,mat));
            mat[i][j] = x;
            return ans;
        }
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size();
        int m = mat[0].size();
        if(word.length() > (n*m)) return false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m ; j++) {
                if(mat[i][j] == word[0]){
                    if(Poss(word,i,j,n,m,0,mat)) return true;
                }
            }
        }    
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends