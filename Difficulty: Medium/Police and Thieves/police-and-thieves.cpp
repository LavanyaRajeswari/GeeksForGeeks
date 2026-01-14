class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        int i = 0, j = 0, ans = 0;
        int t = 0, p = 0;
        while(j < n) {
            // cout << i << " " << j << endl;
            if(j-i > k) {
                i++;
                while(arr[i] == '$' and i <= j) i++;
            }
            if((arr[i] == 'P' and arr[j] == 'T') || (arr[i] == 'T' and arr[j] == 'P') and (j-i) <= k) {
                arr[i] = '$';
                arr[j] = '$';
                ans++;
                i++;
                while(arr[i] == '$' and i <= j) i++;
            }
            j++;
            while(arr[j] == '$' and j < n) j++;
        }
        return ans;
    }
};