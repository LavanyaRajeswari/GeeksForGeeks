//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeDivision(int n) {
        vector<bool>v(n,true);
        vector<int>ans;
        vector<int>x;
        for(int i = 2; i*i < n; i++) {
            if(v[i] == true) {
                for(int j = i*i; j < n; j+=i){
                    v[j] = false;
                }
            }
        }
        for(int i = 2; i < n; i++) {
            if(v[i] == true){
                ans.push_back(i);
            }
        }
        int i = 0, j = ans.size()-1;
        while(i <= j){
            if(ans[i]+ans[j] == n){
                x.push_back(ans[i]);
                x.push_back(ans[j]);
                break;
            }
            else if(ans[i]+ans[j] > n){
                j--;
            }
            else if(ans[i]+ans[j] < n){
                i++;
            }
        }
        return x;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends