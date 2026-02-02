class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n);
        for (int i=0; i<pre.size(); i++){
            int ai = pre[i][0];
            int bi = pre[i][1];
            adj[bi].push_back(ai);
            inDegree[ai]++;
        }
        queue<int> q;
        for (int i=0; i<n; i++){
            if (inDegree[i] == 0) q.push(i);
        }
        while (!q.empty()){
            int course = q.front();
            q.pop();
            for (auto i : adj[course]){
                inDegree[i]--;
                if (inDegree[i] == 0) q.push(i);
            }
        }
        for (int i=0; i<n; i++){
            if (inDegree[i]) return false;
        }
        return true;
    }
};