class Solution {
  public:
    int bin(vector<int>& nums, int target,int low,int high,bool flag) {
        int ans = flag == true ? INT_MAX : -1;
        while(low <= high) {
            int mid = (low+high) / 2;
            if(nums[mid] == target) {
                if(flag){
                    ans = min(ans,mid);
                    high = mid-1;
                }
                else{
                    ans = max(ans,mid);
                    low = mid+1;
                }
            }
            else if(nums[mid] < target) {
                low = mid+1;
            }
            else if(nums[mid] > target) {
                high = mid-1;
            }
        }
        return ans;
    }
  
    vector<int> find(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n-1;
        vector<int>ans = {INT_MAX,-1};
        ans[0] = bin(arr,x,low,high,true);
        if(ans[0] == INT_MAX) return {-1,-1};
        ans[1] = bin(arr,x,ans[0],high,false);
        return ans;
    }
};