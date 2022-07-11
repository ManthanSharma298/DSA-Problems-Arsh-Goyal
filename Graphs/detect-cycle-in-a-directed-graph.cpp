

// DFS using two vis array one for current dfs loop and other for overall
// O(N+E), O(N+N+H) 
class Solution {
  public:
    bool dfs(int node, vector<int>&vis, vector<int>&curr, vector<int> adj[]){
        vis[node] = 1;
        curr[node] = 1;
        
        for(int cld: adj[node]){
            if(!vis[cld]){
                if(dfs(cld, vis, curr, adj)) return true;
            }
            else if(curr[cld]){
                return true;
            }
        }
        
        curr[node] = 0;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> vis(V, 0);
        vector<int> curr(V, 0);
        
        for(int i=0; i<V; ++i){
            if(!vis[i]) if(dfs(i, vis, curr, adj)) return true;
        }
        return false;
    }
};