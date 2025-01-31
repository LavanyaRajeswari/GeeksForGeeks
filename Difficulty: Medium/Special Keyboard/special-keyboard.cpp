//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
public:

    int optimalKeys(int N) {
        vector<int>dp(76);
        for(int i = 0; i <= N; i++) {
            dp[i] = i;
        }
        for(int i = 2; i <= (N-3); i++) {
            int multiple = 2;
            for (int j=i+3; j<=N; j++){
                dp[j] = max(dp[j], dp[i]*multiple++);
            }
        }
        return dp[N];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends