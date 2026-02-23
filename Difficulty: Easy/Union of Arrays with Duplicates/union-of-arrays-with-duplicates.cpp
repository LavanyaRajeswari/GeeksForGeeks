class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        set<int>st;
        vector<int>ans;
        for(auto it:a) st.insert(it);
        for(auto it:b) st.insert(it);
        for(auto it:st) ans.push_back(it);
        return ans;
    }
};