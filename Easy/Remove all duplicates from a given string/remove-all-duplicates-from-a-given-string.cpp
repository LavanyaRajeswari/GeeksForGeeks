//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    string ans;
	    map<char,int>mpp;
	    for(int i=0;i<str.length();i++){
	        if(mpp.find(str[i]) == mpp.end()){
	            ans+=str[i];
	            mpp[str[i]]++;
	        }
	    }
	   // int n=str.size();
	   // unordered_map<char,int>mpp;
	   // string ans = "";
	   // for(int i=0;i<=n;i++){
	   //         mpp[str[i]]++;
	   // }
	   // for(int i=str.size();i>=0;i--){
	   //     if(mpp[str[i]] > 1) mpp[str[i]]--;
	   //     else ans+=str[i];
	   // }
	   // reverse(ans.begin(),ans.end());
	   return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends