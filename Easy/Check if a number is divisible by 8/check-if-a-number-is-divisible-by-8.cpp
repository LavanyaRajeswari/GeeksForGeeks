//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        int n = s.size()-1;
        int ans=0;
        if(n == 0){
           ans = s[0]-'0'; 
        }
        else if(n == 1){
            ans = (ans*10)+(s[0]-'0');
            ans = (ans*10)+(s[1]-'0');
        }
        else if(n == 2){
            ans = (ans*10)+(s[0]-'0');
            ans = (ans*10)+(s[1]-'0');
            ans = (ans*10)+(s[2]-'0');
        }
        else if(n >= 3){
            ans = (ans*10)+(s[n-2]-'0');
            ans = (ans*10)+(s[n-1]-'0');
            ans = (ans*10)+(s[n]-'0');
        }
        //cout<<ans<<endl;
        if(ans % 8 == 0){
            return 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends