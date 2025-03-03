//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        multiset<int>mt;
        vector<int>ans;
        int i = 0, j = 0, n = arr.size(),st = 0, len = 0;
        while(j < n) {
            mt.insert(arr[j]);
            while(abs(*mt.begin()-*mt.rbegin()) > x){
                    mt.erase(mt.find(arr[i]));
                    i++;
            }
            if(j - i + 1 > len) {
                st = i;
                len = max(len,j-i+1);
            }
            j++;
                
        }
        for(int i = st; i < st+len; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends