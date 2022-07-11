

// 1. DFS: O(N+E), O(h)
class Solution {
public:
    void dfs(int i, vector<int> &vis, vector<vector<int>> &g){
        vis[i] = 1;
        
        for(int cld: g[i]){
            if(!vis[cld]) dfs(cld, vis, g);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int e = connections.size();
        if(e < n-1) return -1;
        
        vector<vector<int>> g(n);
        for(auto c: connections){
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
        
        vector<int> vis(n, 0);
        int comp = 0;
        for(int i=0; i<n; ++i){
            if(!vis[i]){
                dfs(i, vis, g);
                comp++;
            }
        }
        return comp-1;
    }
};

// 2. Union find