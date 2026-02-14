class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i] == key and ans == -1) return i;
        }
        return ans;
    }
};