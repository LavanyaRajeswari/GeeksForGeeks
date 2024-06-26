//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    { 
        int n = mat.size();
        vector<int> ans;
        int flag = 1;
        map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mpp[i+j].push_back(mat[i][j]);
            }
        }
        for(int i=0;i<mpp.size();i++){
            if(flag){
                reverse(mpp[i].begin(),mpp[i].end());
            }
            ans.insert(ans.end(),mpp[i].begin(),mpp[i].end());
            flag = !flag;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends