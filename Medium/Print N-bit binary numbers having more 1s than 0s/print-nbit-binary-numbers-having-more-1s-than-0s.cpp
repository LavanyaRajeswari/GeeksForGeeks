//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    vector<string>ans;
    void str(string s,int i,int o,int z,int n){
        if(i == n){
            ans.push_back(s);
            return;
        }
        str(s+'1',i+1,o+1,z,n);
        if(o >= z+1)
        str(s+'0',i+1,o,z+1,n);
    }
	vector<string> NBitBinary(int n)
	{
	    string s = "1";
	    str(s,1,1,0,n);
	    sort(ans.rbegin(),ans.rend());
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends