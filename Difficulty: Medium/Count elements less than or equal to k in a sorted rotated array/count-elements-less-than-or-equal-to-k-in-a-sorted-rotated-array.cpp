class Solution {
    public:
    int countLessEqual(vector<int>& arr, int x) {
        sort(arr.begin(),arr.end());
        int i = 0, j = arr.size();
        int ans = 0;
        // for(int i = 0; i < j ; i++) {
        //     cout << arr[i] << " ";
        // }
        // cout<<endl;
        i = 0;
        if(arr[j-1] < x) return j;
        while(i <= j) {
            int m = (i+j) / 2;
            if(arr[m] < x) {
                i = m + 1;
                ans = m+1;
            }
            if(arr[m] > x) {
                j = m - 1;
            }
            // cout << arr[m] << " " << ans << " " << m << endl;
            if(arr[m] == x) {
                return m+1;
            }
        }
        return ans;
    }
};