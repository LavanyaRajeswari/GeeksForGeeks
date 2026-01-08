class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        int j = 0,c = 0;
        int ans = 0,r1 = 0, r2 = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] % 2) c++;
            while(c > k) {
                if(arr[j] % 2) c--;
                j++;
            }
            r1 += (i - j + 1);
        }
        j = 0;c = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] % 2) c++;
            while(c > k-1) {
                if(arr[j] % 2) c--;
                j++;
            }
            r2 += (i - j + 1);
        }
        ans = r1 - r2;
        return ans;
    }
};