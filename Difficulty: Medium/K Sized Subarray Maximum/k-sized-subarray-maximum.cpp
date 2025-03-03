//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int>ans;
        multiset<int>st;
        for(int i = 0; i < k; i++) {
            st.insert(arr[i]);
        }
        int i = 0, j = k,n = arr.size();
        ans.push_back(*st.rbegin());
        while(j < n) {
            // for(auto it:st) {
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            st.erase(st.find(arr[i]));
            st.insert(arr[j]);
            ans.push_back(*st.rbegin());
            j++;
            i++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends