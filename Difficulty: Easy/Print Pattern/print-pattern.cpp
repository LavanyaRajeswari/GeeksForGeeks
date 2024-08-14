//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int>ans;
    int flag = 0,x = 0,f = 0;
    vector<int> pattern(int N){
        if(N > 0 and flag == 0){
            ans.push_back(N);
            pattern(N-5);
            f = 1;
        }
        if(N <= 0){
            flag = 1;
            x = ans.size();
            ans.push_back(N);
            if(f != 0){
                pattern(N+5);
            }
        }
        else if(N <= ans[0]  and flag == 1 and ans.size() <= x*2){
            ans.push_back(N);
            pattern(N+5);
        }
        return ans;
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
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends