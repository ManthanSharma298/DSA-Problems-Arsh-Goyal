

// DFS: O(V+E), O(N)
class Solution {
  public:
    bool dfs(int node, int par, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        for(int cld: adj[node]){
            if(!vis[cld]){
                if(dfs(cld, node, adj, vis)) return true;
            }
            else if(cld != par) return true;
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                if(dfs(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};