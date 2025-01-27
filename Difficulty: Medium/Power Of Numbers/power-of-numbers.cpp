//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int reverse(int n){
        int cur = 0;
        while (n){
            cur = cur*10 + (n%10);
            n /= 10;
        }
        return cur;
    }
    int power(int base,int expo){
        if (expo == 0) return 1;
        if (expo == 1) return base;
        int half = power(base, expo/2);
        int rem = power(base, expo%2);
        return half*half*rem;
    }
    int reverseExponentiation(int n) {
        // code here
        int base = n, expo = reverse(n);
        return power(base, expo);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T; // test cases

    while (T--) {
        int n;
        cin >> n; // input N

        Solution ob;
        // power of the number to its reverse
        int ans = ob.reverseExponentiation(n);
        cout << ans << endl;
    }

    return 0;
}

// } Driver Code Ends