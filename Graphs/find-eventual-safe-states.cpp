

// DFS using map: O(n), O(n+n)
class Solution {
    map<int, int> isSafe;
    vector<vector<int>> g;
public:
    bool dfs(int i){
        isSafe[i] = 0;
        int f = 1;
        for(int id: g[i]){
            if(!isSafe.count(id)){
                if(dfs(id) == false) f = 0;
            }
            else{
                if(isSafe[id] == 0) f = 0;
            }
        }
        if(f) isSafe[i] = 1;
        return isSafe[i];
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        this->g = graph;
        for(int i=0; i<g.size(); ++i){
            if(!isSafe.count(i)){
                dfs(i);
            }
        }
        vector<int> res;
        for(auto e: isSafe){
            if(e.second) res.push_back(e.first);
        }
        return res;
    }
};

// 2. Using extra vector: O(n), O(n+n+n)
class Solution {
public:
    void dfs(int node, vector<int>& trm, vector<int>& vis, vector<vector<int>>& g){
        vis[node] = 1;
        int f = 1;
        for(int cld: g[node]){
            if(!vis[cld]) dfs(cld, trm, vis, g);
            if(trm[cld] == 0){
                f = 0;
                break;
            }  
        }
        
        trm[node] = f;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> trm(n, 0);
        vector<int> vis(n, 0);
        
        for(int i=0; i<n; ++i){
            if(!vis[i]){
                dfs(i, trm, vis, graph);
            }
        }
        
        vector<int> res;
        for(int i=0; i<n; ++i) {
            if(trm[i]) res.push_back(i);
        }
        
        return res;
    }
};