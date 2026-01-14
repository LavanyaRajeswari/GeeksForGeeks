class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        int i = 0, j = 1,n = s.length();
        if(n <= 0) return 0;

        map<char,int>mp;
        map<char,int>p;
        mp[s[i]]++;
        int ans = 1;
        while(j < n) {
            if(mp[s[j]] == 0) {
                mp[s[j]]++;
            }
            else{
                if(s[j] != s[i]) {
                    while(i < j and s[i] != s[j]) {
                        mp[s[i]]--;
                        i++;
                    }
                }
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};