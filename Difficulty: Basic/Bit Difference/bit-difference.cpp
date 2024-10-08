//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        if(a == b) return 0;
        int ans = 0;
        if(a > b){
            while(a){
                if((a&1) != (b&1)){
                    ans++;
                }
                b >>= 1;
                a >>= 1;
            }
        }
    else{
        while(b){
            if((b&1) != (a&1)){
            // cout<<(b&1)<<" "<<(a&1)<<endl;
                ans++;
            }
            a >>= 1;
            b >>= 1;
        }
    }   
    return ans;   
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}
// } Driver Code Ends