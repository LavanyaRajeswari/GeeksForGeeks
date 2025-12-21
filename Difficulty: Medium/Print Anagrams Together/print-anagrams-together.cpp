// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        int n = arr.size();
        vector<vector<string>>ans;
        map<string,int>mp;
        int j = 0;
        for(int i = 0; i < n; i++) {
            string s = arr[i];
            sort(s.begin(),s.end());
            if(mp.find(s) != mp.end()) {
                ans[mp[s]].push_back(arr[i]);
            } 
            else{
                mp[s] = j;
                ans.push_back({arr[i]});
                j++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};