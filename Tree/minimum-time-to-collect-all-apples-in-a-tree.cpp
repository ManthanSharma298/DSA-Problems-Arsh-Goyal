

// O(N), O(H + N) for vis array
class Solution {
public:
    int dfs(int node, vector<int>& vis, vector<bool>& is, vector<vector<int>>& g) {
        vis[node] = 1;
        
        int ans = 0;
        for(int cld: g[node]) {
            if(!vis[cld]) {
                int d = dfs(cld, vis, is, g);
                if(d > 0 || is[cld]) ans += d+2;
            }
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> g(n);
        for(auto edge: edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n);
        return dfs(0, vis, hasApple, g);
    }
};