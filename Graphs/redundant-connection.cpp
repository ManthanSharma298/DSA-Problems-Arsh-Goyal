

// DFS solution: O(N**2), O(N**2)
class Solution {
    int n;
public:
    bool isCycle(int node, int par, vector<vector<int>>& g, vector<int> &vis){
        vis[node] = 1;
        for(int i=1; i<=n; ++i){
            if(g[node][i] == 1){
                // i is cld of node
                if(!vis[i]){
                    if(isCycle(i, node, g, vis)) return true;
                }
                else if(i != par) return true;
            }
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        this->n = n;
        vector<vector<int>> g(n+1, vector<int>(n+1, 0));
        
        for(auto e: edges){
            g[e[0]][e[1]] = 1;
            g[e[1]][e[0]] = 1;
        }
        
        // checking for every node
        for(int i=n-1; i>=0; --i){
            auto e = edges[i];
            // need to remove e
            g[e[0]][e[1]] = 0;
            g[e[1]][e[0]] = 0;
            
            vector<int> vis(n+1, 0);
            int f = 1;
            for(int i=1; i<=n; ++i){
                if(!vis[i]){
                    if(isCycle(i, -1, g, vis)){
                        f = 0;
                        break;
                    }
                }
            }
            if(f){
                return e;
            }
            g[e[0]][e[1]] = 1;
            g[e[1]][e[0]] = 1;
        }
        return {};
    }
};


// 