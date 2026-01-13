class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int n = arr.size(), x = 0, y = 0, z = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 5) {
                x++;
            }
            if(arr[i] == 10) {
                if(x > 0) {
                    y++;
                    x--;
                }
                else{
                    return false;
                }
            }
            if(arr[i] == 20) {
                if(y >= 1 and x >= 1) {
                    y--;
                    x--;
                }
                else if(y == 0 and x >= 3) {
                    x -= 3;
                }
                else {
                    return false;
                }
                z++;;
            }
        }
        return true;
    }
};