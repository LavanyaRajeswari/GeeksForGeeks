//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {
        float a1 = 0, a2 = 0, b1 = 0, b2 = 0, i = 0, n = str.length();
        int flag = 0;
        string ans1 = "",ans2 = "";
        while(i<n){
            while(flag == 0){
                ans1+=str[i];
                if(str[i] == '/'){
                    i++;
                    flag = 1;
                }
                else{
                a1 = a1*10+(str[i]-'0');
                i++;
                }
            }
            while(flag == 1){
                if(str[i] == ','){
                    i+=2;
                    flag = 2;
                }
                else{
                ans1+=str[i];
                a2 = a2*10+(str[i]-'0');
                i++;
                }
            }
            while(flag == 2){
                ans2 += str[i];
                if(str[i] == '/'){
                    flag = 3;
                    i++;
                }
                else{
                b1 = b1*10+(str[i]-'0');
                i++;
                }
            }
            while(flag == 3 and i < n){
                ans2 += str[i];
                b2 = b2*10+(str[i]-'0');
                i++;
            }
        }
        float x = a1/a2, y = b1/b2;
        if(x > y){
            return ans1;
        }
        if(x < y){
            return ans2;
        }
        return "equal";
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends