


class Solution {
public:
    void generateParent(int node, int par, int dist, vector<int>& pr, vector<int>& d, vector<vector<int>>& g) {
        pr[node] = par;
        d[node] = dist;
        for(int cld: g[node]) {
            if(cld != par) {
                generateParent(cld, node, dist+1, pr, d, g);
            }
        }
    } 
    int dfs(int node, vector<int>& amount, vector<int>& vis, vector<vector<int>>& g) {
        vis[node] = 1;
        int currSum = amount[node], mxVal = INT_MIN;
        for(int cld: g[node]) {
            if(!vis[cld]) {
                mxVal = max(mxVal, dfs(cld, amount, vis, g));
            }
        }
        currSum += (mxVal == INT_MIN ? 0 : mxVal);
        return currSum;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // construct graph
        int n = edges.size();
        vector<vector<int>> g(n+1);
        for(auto &edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        // we need parent array for bob to traverse
        vector<int> par(n+1);
        vector<int> dist(n+1); 
        par[0] = -1; 
        generateParent(0, -1, 0, par, dist, g);
        
        // for bob
        int curr = bob;
        int currDist = 0;
        while(curr != 0) {
            // bob will reach here first
            if(currDist < dist[curr]) {
                amount[curr] = 0;
            }
            // both reach here simultaneously
            else if(currDist == dist[curr]) {
                amount[curr] /= 2;
            }
            curr = par[curr];
            currDist++;
        }
        vector<int> vis(n+1, 0);
        return dfs(0, amount, vis, g);
    }
};