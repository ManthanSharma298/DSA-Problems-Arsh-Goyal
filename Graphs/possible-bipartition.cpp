

// Bipartition
// 1. BFS: O(N+E), O(N)
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n+1);
        for(auto e: dislikes){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> clr(n+1, -1);
        queue<int> q;
        
        int color;
        for(int i=1; i<=n; ++i){
            if(clr[i] == -1){
                q.push(i);
                clr[i] = 0;
                color = 1;
            }
            while(!q.empty()){
                int sz = q.size();
                while(sz--){
                    int node = q.front();
                    q.pop();

                    for(int cld: g[node]){
                        // not visited
                        if(clr[cld] == -1){
                            q.push(cld);
                            clr[cld] = color;
                        }
                        // visited
                        else if(clr[node] == clr[cld]) return false;
                    }
                }
                color = (color+1)%2;
            }
        }
        return true;
    }
};


// 2. DFS: O(N+E), O(N)
class Solution {
public:
    bool dfs(int node, int paint, vector<vector<int>>& adj, vector<int>& color){
        color[node] = paint;
        paint = (paint == 1) ? 0 : 1;
        for(int cld: adj[node]){   
            if(color[cld] == -1){
                if(!dfs(cld, paint, adj, color)){
                    return false;
                }
            }
            else if(color[cld] == color[node]){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int paint = 0;
        vector<vector<int>> adj(n+1);
        vector<int>color(n+1, -1);
        for(auto val: dislikes){
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        for(int i=1; i<=n; ++i){
            if(color[i] == -1 && !dfs(i, paint, adj, color)){
                return false;
            }
        }
        return true;
    }
};
