class Solution {
public:
    void fun(vector<int>candidates,int size,int i,vector<vector<int>>&ans,vector<int>v,int sum,int target){
        if(sum == target){
            ans.push_back(v);
            return;
        }
        if(i >= size){
            return;
        }
        if(sum > target){
            return;
        }
        v.push_back(candidates[i]);
        fun(candidates,size,i,ans,v,sum+candidates[i],target);
        v.pop_back();
        fun(candidates,size,i+1,ans,v,sum,target);
    }
    vector<vector<int>> targetSumComb(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v(0);
        fun(candidates,candidates.size(),0,ans,v,0,target);
        return ans;
    }
};