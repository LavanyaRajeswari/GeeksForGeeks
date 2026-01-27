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

