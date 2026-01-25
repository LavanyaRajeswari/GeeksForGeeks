class Solution {
  public:
    int rec(int x, int y) {
        if(x < 0 || y < 0) return 0;
        if(x == 0 && y == 1) return 1;
        int o = rec(x-1,y);
        int c = 0;
        if(x < y) {
            c = rec(x,y-1);
        }
        return o+c;
    }
    int findWays(int n) {
        if(n%2) return 0;
        int ans = rec(n/2,n/2);
        return ans;
    }
};