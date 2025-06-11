class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        int n = color.size();
        stack<pair<int,int>>st;
        for(int i = 0; i < n; i++) {
            if(!st.empty()){
                pair<int,int>p = st.top();
                if(p.first == color[i] and p.second == radius[i]) {
                    st.pop();
                }
                else{
                    st.push({color[i],radius[i]});
                }
            }
            else{
                st.push({color[i],radius[i]});
            }
        }
        return st.size();
    }
};