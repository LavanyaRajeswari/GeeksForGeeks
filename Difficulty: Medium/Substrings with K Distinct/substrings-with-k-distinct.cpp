class Solution {
  public:
    
    int solve(string& s,int k,vector<int>v) {
        int n = s.length(),c = 0, cnt = 0, j = 0;
        for(int i = 0; i < n; i++) {
            if(v[s[i]-'a'] == 0) {
                c++;
            }
            v[s[i]-'a']++;
            while(j <= i and c > k) {
                v[s[j]-'a']--;
                if(v[s[j]-'a'] == 0) {
                    c--;
                }
                j++;
            }
            cnt += (i-j+1);
        }
        return cnt;
    }
    int countSubstr(string& s, int k) {
        vector<int>v(26);
        int n = s.length();
        int ans = solve(s,k,v) - solve(s,k-1,v);
        return ans;
    }
};