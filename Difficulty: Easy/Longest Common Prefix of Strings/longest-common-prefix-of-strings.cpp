//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        int j = 0;
        string ans = "";
        for(int i = 0; i < arr[0].size(); i++) {
            string x = "";
            int size = arr.size(),k = 0,c = 0;
            unordered_map<char,int>mp;
            while(size){
                string str = arr[k];
                x += str[j];
                size--;
                k++;
                mp[str[j]]++;
            }
            for(auto it:mp){
                c = it.second;
            }
            if(c == arr.size()){
                ans += x[0];
                j++;
            }
            else{
                break;
            }
            
        }
        (ans == "") ? ans = "-1" : ans;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends