//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        int ans = 0,temp1 = n,temp2 = n,i = 0;
        while(temp1){
            temp1/=10;
            i++;
        }
        while(temp2){
            ans+=(pow((temp2%10),i));
            temp2/=10;
        }
        if(ans == n) return "true";
        return "false";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends