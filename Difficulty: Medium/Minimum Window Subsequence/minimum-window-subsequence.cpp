class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n = s1.length(), m = s2.length();
        string ans = "";
        int i = 0, j = 0;
        int len = INT_MAX;
        while (i < n) {
            if (s1[i] == s2[j]) j++;
            if (j == m) {
                int ed = i;
                j = m - 1;
                while (i >= 0 && j >= 0) {
                    if (s1[i] == s2[j]) j--;
                    i--;
                }
                i++;

                if (ed - i + 1 < len) {
                    len = ed - i + 1;
                    ans = s1.substr(i, len);
                }

                j = 0;
            }
            i++;
        }

        return ans;
    }
};
