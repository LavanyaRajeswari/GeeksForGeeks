class Solution {
  public:
    bool areIsomorphic(string &s, string &t) {
     
        map<char,char>mp;
        map<char,int>mpp;
        int n = s.length(), m = t.length();
        if(n != m) return false;
        for(int i = 0; i < n; i++) {
            if(mp.find(s[i]) == mp.end() and mpp.find(t[i]) == mpp.end()){
                mp[s[i]] = t[i];
                mpp[t[i]]++;
            }
            s[i] = mp[s[i]];
        }
        if(s != t) return false;
        return true;
    }
};
