class Solution {
  public:
    void pushZerosToEnd(vector<int>& nums) {
        int n = nums.size();
        nums.erase(remove(nums.begin(),nums.end(),0),nums.end());
        int c = n - nums.size();
        while(c--) {
            nums.push_back(0);
        }
    }
};