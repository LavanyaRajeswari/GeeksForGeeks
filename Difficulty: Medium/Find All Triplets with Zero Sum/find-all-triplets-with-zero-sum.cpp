// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        int n = arr.size();
        int i = 0, j = 1,k = n-1;
        map<vector<int>,int>mpp;
        vector<vector<int>>ans;
        map<int,int>mp;
        for(int i = 0; i < n ; i++) {
            mp[arr[i]] = i;
        }
        while(i < n) {
            j = i+1;
            while(j < n){
            int x = 0 - (arr[i]+arr[j]);
            if(mp.find(x) != mp.end() and mp[x] != i and mp[x] != j) {
                vector<int>cur = {i,j,mp[x]};
                sort(cur.begin(),cur.end());
                mpp[cur]++;
            }
            j++;
            }
            i++;
        }
        for(auto it:mpp) {
            ans.push_back(it.first);
        }
        return ans;
    }
};