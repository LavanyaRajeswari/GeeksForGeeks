class Solution {
public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        
        int i = 0, j = 0, k = 0;
        int minDiff = INT_MAX;
        int minSum = INT_MAX;
        vector<int> ans;
        
        while (i < a.size() && j < b.size() && k < c.size()) {
            int mn = min({a[i], b[j], c[k]});
            int mx = max({a[i], b[j], c[k]});
            int diff = mx - mn;
            int sum = a[i] + b[j] + c[k];
            
            if (diff < minDiff || (diff == minDiff && sum < minSum)) {
                minDiff = diff;
                minSum = sum;
                ans = {a[i], b[j], c[k]};
            }
            
            if (a[i] == mn) ++i;
            else if (b[j] == mn) ++j;
            else ++k;
        }
        sort(ans.rbegin(),ans.rend());
        return ans;
    }
};
