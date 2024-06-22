//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {
        long long ans = -1,cur = -1,n = s.length(),m = -1,i = 0;
            while(i < n) {
                cur = -1;
                if(s[i]-'0' <= 8 and s[i]-'0' >= 0){
                    while(s[i]-'0' <= 8 and s[i]-'0' >= 0){
                        if(cur == -1){
                            cur = (s[i]-'0');
                        }
                        else{
                        cur = (cur*10) + (s[i]-'0');
                        }
                    i++;
                    }
                }
                else if(s[i]-'0' == 9){
                    cur = -1;
                    i++;
                    while(s[i]-'0' <= 9 and s[i]-'0' >= 0 and i < n){
                        i++;
                    }
                }
                else{
                    i++;
                }
            m = max(m, cur);
        }
        if(m > ans) return m;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends