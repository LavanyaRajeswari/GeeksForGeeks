//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        int num = 0;
        for (int i = 0; i < str.length(); i++) {
            if(str[i] != '.'){
                num = num * 10 + (str[i] - '0');
            }
            if((str[i] == '.') || (i == str.length()-1)){
                if(num > 255 || num < 0){
                    return false;
                }
                num = 0;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends