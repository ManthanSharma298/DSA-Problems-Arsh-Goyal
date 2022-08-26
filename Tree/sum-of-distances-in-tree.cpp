

// DP on Trees: O(n), O(n)
class Solution {
public:
    void getSum(int node, int par, vector<int>& dist, vector<int>& vis, vector<int>& subCnt, vector<vector<int>>& g){
        vis[node] = 1;
        if(par != -1) {
            dist[node] = dist[par] - subCnt[node] + (g.size() - subCnt[node]);
        }
        
        // need to update it before going to the childs
        for(int cld: g[node]){
            if(!vis[cld]){
                getSum(cld, node, dist, vis, subCnt, g);
            }
        }
    }
    int dfs(int node, vector<int>& subCnt, vector<int>& vis, vector<vector<int>>& g){
        vis[node] = 1;
        int cnt = 1;
        for(int cld: g[node]){
            if(!vis[cld]){
                cnt += dfs(cld, subCnt, vis, g);
            }
        }
        
        return subCnt[node] = cnt;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto vec: edges){
            g[vec[0]].push_back(vec[1]);
            g[vec[1]].push_back(vec[0]);
        }
        
        vector<int> subCnt(n);
        vector<int> vis(n, 0);
        dfs(0, subCnt, vis, g);
        
        int level = 0;
        queue<int> q;
        for(int i=0; i<n; ++i) vis[i] = 0;
        
        vis[0] = 1;
        q.push(0);
        vector<int> dist(n, 0);
        while(!q.empty()){
            int sz = q.size();
            dist[0] += sz*level;
            while(sz--){
                int node = q.front();
                q.pop();
                
                for(int cld: g[node]){
                    if(!vis[cld]){
                        q.push(cld);
                        vis[cld] = 1;
                    } 
                }
            }
            level++;
        }
        
        for(int i=0; i<n; ++i) vis[i] = 0;
        getSum(0, -1, dist, vis, subCnt, g);
        
        return dist;
    }
};