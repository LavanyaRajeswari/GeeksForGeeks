//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        map<char,int>mp;
        for(int i = 0; i < str.length();i++){
            if(str[i] != ' '){
            mp[str[i]]++;
            }
        }
        int c = 0,tc = 0;
        for(auto it:mp){
            c++;
            tc += it.second;
            
        }
        int x = 26 - c;
        if(tc < 26 || x > k){
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends