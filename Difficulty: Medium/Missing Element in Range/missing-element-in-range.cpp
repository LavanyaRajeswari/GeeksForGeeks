class Solution {
public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        sort(arr.begin(), arr.end());
        vector<int> ans;

        int curr = low;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < low) continue;
            if (arr[i] > high) break;

            while (curr < arr[i]) {
                ans.push_back(curr);
                curr++;
            }
            curr = arr[i] + 1;
        }

        while (curr <= high) {
            ans.push_back(curr);
            curr++;
        }

        return ans;
    }
};
