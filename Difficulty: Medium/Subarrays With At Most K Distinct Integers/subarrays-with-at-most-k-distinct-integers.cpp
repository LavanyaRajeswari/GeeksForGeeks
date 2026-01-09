class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        int ans = 0,j = 0;
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
            if(mp[arr[i]] == 1) k--;
            while(k < 0) {
                mp[arr[j]]--;
                if(mp[arr[j]] == 0) k++;
                j++;
            }
            ans += (i-j+1);
        }
        return ans;
    }
};