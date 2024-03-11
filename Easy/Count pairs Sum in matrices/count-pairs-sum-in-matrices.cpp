//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    vector<int>v1;
	    vector<int>v2;
	    int count = 0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            v1.push_back(mat1[i][j]);
	            v2.push_back(mat2[i][j]);
	        }
	    }
	    sort(v1.begin(),v1.end());
	    sort(v2.begin(),v2.end());
	    if(n == 1){
	        if(v1[0]+v2[0] == x){
	            return 1;
	        }
	    }
	    else{
    	    int i = 0,j = v2.size()-1;
    	    while(i<v1.size() and j>=0){
    	        if(v1[i]+v2[j] == x){
    	           // cout<<v1[i]<<" "<<v2[j]<<endl;
    	            i++;
    	            j--;
    	            count++;
    	        }
    	        else if(v1[i]+v2[j] > x){
    	            j--;
    	        }
    	        else if(v1[i]+v2[j] < x){
    	            i++;
    	        }
    	    }
	    }
	    return count;
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
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends