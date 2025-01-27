//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    
    map<int,string> v = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    void PossWords(vector<int>&arr, int i, vector<string>&ans, string s) {
        if(s.length() == arr.size()) {
            ans.push_back(s);
            return;
        }
        for (int ind = 0; ind < v[arr[i]].size(); ind++){
            PossWords(arr,i+1,ans,s+v[arr[i]][ind]);
        }
        // if(arr[i] - 2 < 0 && i >= arr.size() || j >= v[arr[i]-2].size()) {
        //     return;
        // }
        // s.push_back(v[arr[i]-2][j]);
        // PossWords(arr,i+1,0,mp,s);
        // s.pop_back();
        // PossWords(arr,i,j+1,mp,s);
        
    }
    
    vector<string> possibleWords(vector<int> &arr) {
        vector<string>ans;
        PossWords(arr, 0, ans, "");
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        vector<string> v = obj.possibleWords(a);

        Array::print(v);
        cout << "~" << endl;
    }
}

// } Driver Code Ends