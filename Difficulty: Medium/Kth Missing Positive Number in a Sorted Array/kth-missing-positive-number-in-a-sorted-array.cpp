class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size();
        int j = 1,ans = 0;
        for(int i = 0; i < n ; i++) {
            while(j < arr[i] and k > 0) {
                k--;
                ans = j;
                j++;
            }
            j++;
        }
        while(k > 0) {
            ans = j;
            j++;
            k--;
        }
        return ans;
    }
};