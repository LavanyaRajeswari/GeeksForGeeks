//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int n, int arr[]) {
        map<int,int>mp;
        vector<int>ans;
        for(int i = 0; i < n+2; i++ ) {
            if(mp.find(arr[i]) != mp.end()){
                ans.push_back(arr[i]);
            }
            else{
                mp[arr[i]]++;
            }
        }
       return ans; 
    }
};

//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        int arr[n + 2];

        for (int i = 0; i < n + 2; i++)
            cin >> arr[i];

        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(n, arr);
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}

// } Driver Code Ends