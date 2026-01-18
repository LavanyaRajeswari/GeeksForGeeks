class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n = arr.size();
        vector<int>ans(n+1,-1);
        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        stack<int> st;              
        for (int i = 0; i < n; i++) {
            while (!st.empty() && mp[arr[i]] > mp[arr[st.top()]]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
