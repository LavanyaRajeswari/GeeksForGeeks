//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        vector<int>mini(n,a[0]);
        vector<int>maxi(n,a[n-1]);
        int mx = a[n-1],min = a[0];
        for(int i=1;i<n;i++){
            if(a[i] < min) min = a[i];
            mini[i] = min;
        }
        for(int i=n-2;i>=0;i--){
            if(a[i] > mx) mx = a[i];
            maxi[i] = mx;
        }
        int left=0;
        int right=0;
        int ans=0;
           while(left<n && right<n){
               if (mini[left]<=maxi[right]){
                   ans=max(ans,right-left);
                   right+=1;
               }
               else{
                   left+=1;
               }
           }
       return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends