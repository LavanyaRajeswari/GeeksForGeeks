class Solution {
  public:
    void solution(string &s,int start,map<string,int>&ans){
        if(start == s.size()){
            ans[s]++;
            return;
        }
        for(int i=start;i<s.size();i++){
            swap(s[start],s[i]);
            solution(s,start+1,ans);
            swap(s[start],s[i]);
        }
    }
    vector<string> findPermutation(string &s) {
        map<string,int>ans;
        vector<string>res;
        solution(s,0,ans);
        for(auto it:ans) {
            res.push_back(it.first);
        }
        return res;
    }
};
