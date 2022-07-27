

// Topolocical sort and cycle detection: O(N+E), O(N)
class Solution {
    vector<vector<int>> g;
    vector<int> order;
public:
    bool isCyclic(int i, vector<int>& vis, vector<int>& curr){
        vis[i] = 1;
        curr[i] = 1;
        
        for(int cld: g[i]){
            if(!vis[cld]){
                if(isCyclic(cld, vis, curr)) return true;
            }
            else if(curr[cld]) return true;
        }
        // unmark that node
        curr[i] = 0;
        // push in order
        order.push_back(i);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> tmp(n);
        g = tmp;
        
        for(auto e: pre){
            g[e[0]].push_back(e[1]);
        }
        
        vector<int> vis(n, 0);
        vector<int> curr(n, 0);
    
        for(int i=0; i<n; ++i){
            if(!vis[i]){
                if(isCyclic(i, vis, curr)) return {};
            }
        }
        return order;
    }
}; 