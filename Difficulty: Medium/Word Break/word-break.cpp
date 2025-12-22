class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        map<string,int> mp;
        int mws = 0;
        for (string word : wordDict){
            mp[word]++;
            int si = word.size();
            mws = max(mws, si);
        }
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for (int i=0; i<n; i++){
            for (int j=i; j<min(n,i+mws); j++){
                string word = s.substr(i,j-i+1);
                if (mp.find(word) != mp.end() && dp[i]==1){
                    dp[j+1] = 1;
                }
            }
        }
        return dp[n];
    }
};