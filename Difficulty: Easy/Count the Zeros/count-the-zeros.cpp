//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        int ans = 0;
        if(arr[0] == 0){
            return arr.size();
        }
        else{
        int i = 1, j = arr.size();
        while(i <= j){
            int mid = (i+j)/2;
            if(arr[mid-1] == 1 and arr[mid] == 0){
                ans = (arr.size()-mid);
                break;
            }
            else if(arr[mid] == 1) {
                i = mid+1;
            }
            else if(arr[mid] == 0) {
                j = mid-1;
            }
        }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.countZeroes(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends