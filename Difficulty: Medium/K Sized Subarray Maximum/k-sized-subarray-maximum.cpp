class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;  
        int n = arr.size();
        
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(arr[dq.front()]);
        for(int i = k; i < n; i++) {
            if(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            while(!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};
