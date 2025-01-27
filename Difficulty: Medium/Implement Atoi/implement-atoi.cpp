//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long ans = 0;
    void num (int i, string s) {
        if(i == s.length() || s[i]-'0' > 9 || s[i]-'0' < 0) {
            return;
        }
        ans = ans*10 + (s[i]-'0');
        num(i+1,s);
    }
    int myAtoi(char *s) {
        if(s[0] == '-') {
            num(1,s);
            ans *= -1;
        }
        else{
            num(0,s);
        }
        if(ans > 2147483647) return 2147483647;
        if(ans < -2147483648) return -2147483648;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends