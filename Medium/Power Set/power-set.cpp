//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int n = pow(2,(s.length()))-1;
		    vector<string>v;
		    for(int i=1;i<=n;i++){
		        int temp = i,j = 0;
		        int a = pow(2,(s.length()-1));
		        string x = "";
		        while(a!=0){
		            if(a&temp) x+=s[j];
		            a>>=1;
		            j++;
		        }
		        v.push_back(x);
		    }
		    sort(v.begin(),v.end());
		    return v;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends