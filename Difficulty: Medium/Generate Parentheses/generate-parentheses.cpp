//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void rec(int n ,int l ,int r, string s,vector<string>&ans) {
        if(l < r || l > n || r > n) {
            return;
        }
        if(s.length() == (2*n)) {
            ans.push_back(s);
        }
        rec(n,l,r+1,s+')',ans);
        rec(n,l+1,r,s+'(',ans);
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string>ans;
        rec(n,1,0,"(",ans);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	
cout << "~" << "\n";
}
	return 0; 
} 

// } Driver Code Ends