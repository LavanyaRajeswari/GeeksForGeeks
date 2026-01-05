class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        if(n < k) return -1;
        int ans = 0;
        int i = 0,j = 0,sum = 0;
        while(j < n) {
            sum += arr[j];
            if((j-i+1) == k) {
                ans = max(sum,ans);
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};