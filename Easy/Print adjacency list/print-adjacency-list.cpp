//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        map<int,vector<int>>map;
        for(int i=0;i<edges.size();i++){
            if(map.find(edges[i].first)!=map.end()){
                vector<int>ans;
                ans = map[edges[i].first];
                ans.push_back(edges[i].second);
                map[edges[i].first] = ans;
                if(map.find(edges[i].second)!=map.end()){
                    vector<int>k;
                    k = map[edges[i].second];
                    k.push_back(edges[i].first);
                    map[edges[i].second] = k;
                }
                else{
                    map[edges[i].second] = {edges[i].first};
                }
            }
            else{
                map[edges[i].first] = {edges[i].second};
                if(map.find(edges[i].second)!=map.end()){
                    vector<int>l;
                    l = map[edges[i].second];
                    l.push_back(edges[i].first);
                    map[edges[i].second] = l;
                }
                else{
                    map[edges[i].second] = {edges[i].first};
                }
            }
        }
        vector<vector<int>>v;
        for(int i=0;i<=V;i++){
            vector<int>a;
            for(auto it:map[i]){
            a.push_back(it);
            }
            v.push_back(a);
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>>edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i=0;i<V;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends