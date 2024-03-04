//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int>q;
        vector<int>ans;
        vector<int>v(V,0);
        q.push(0);
        ans.push_back(0);
        v[0] = 1;
        while(!q.empty()){
            for(int j=0;j<adj[q.front()].size();j++){
                if(v[adj[q.front()][j]] == 0){
                    ans.push_back(adj[q.front()][j]);
                    v[adj[q.front()][j]] = 1;
                    q.push(adj[q.front()][j]);
                }
            }
            q.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends