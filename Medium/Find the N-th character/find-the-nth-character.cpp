//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        char ans;
        for(int i=0;i<r;i++){
            string x;
            s = s.substr(0,n+1);
                for(int j=0;j<s.length();j++){
                    if(s[j] == '0'){
                        x+='0';
                        x+='1';
                    }
                    else{
                        x+='1';
                        x+='0';
                    }
                }
                ans = x[n];
                s = x;
        }
        if(r==0 and n==0){
            ans = s[0];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends