//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setKthBit(int N, int K)
    {
        int temp = N;
        int i = 0;
        while(temp){
            if((i == K) and ((temp&1) == 0)) {
                N += pow(2,i);
                break;
            }
            i++;
            temp >>= 1;
        }
        return N;
    }
    
};




//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        
        Solution ob;
        int ans = ob.setKthBit(N,K);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends