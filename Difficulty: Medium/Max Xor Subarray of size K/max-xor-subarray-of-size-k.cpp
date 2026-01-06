class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0, j = 0;
        int x = 0,ans = 0;
        while(j < n) {
            x ^= arr[j];
            if((j-i+1) == k) {
                ans = max(ans,x);
                x ^= arr[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};