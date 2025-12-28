class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &q) {
        sort(arr.begin(),arr.end());
        vector<int>ans;
        int n = q.size();
        for(int i = 0 ; i < n; i++) {
            auto lb = lower_bound(arr.begin(),arr.end(),q[i][0]);
            auto ub = upper_bound(arr.begin(),arr.end(),q[i][1]);
            int li = lb - arr.begin();
            int ui = ub - arr.begin();
            ans.push_back(ui-li);
        }
        return ans;
    }
};