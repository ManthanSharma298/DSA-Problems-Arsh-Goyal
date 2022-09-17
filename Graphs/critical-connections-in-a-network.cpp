

// dfs: O(N + E), O(N)
class Solution {
public:
    vector<vector<int>> res;
    int time = 1;
    
    void dfs(int node, int par, vector<int>& vis, vector<int>& t, vector<vector<int>>& g){
        vis[node] = 1;
        t[node] = time++;
        int curr = t[node];
        
        
        for(int cld: g[node]){
            if(cld == par) continue;
            if(!vis[cld]){
                dfs(cld, node, vis, t, g);
            }
            t[node] = min(t[node], t[cld]);
            if(t[cld] > curr){
                res.push_back({node, cld});  
            } 
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        for(auto c: connections){
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
        vector<int> vis(n, 0);
        vector<int> t(n, 0);
        dfs(0, -1, vis, t, g); 
        return res;
    }
};