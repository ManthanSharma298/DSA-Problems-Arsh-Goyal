

// Detect cycle in directed graph: O(n), O(h+n+n)
class Solution {
public:
    bool acyclic(int i, vector<int> &vis, vector<int> &curVis, vector<int> grp[]){
        vis[i] = 1;
        curVis[i] = 1;
        
        for(int cld: grp[i]){
            if(!vis[cld] && !acyclic(cld,vis,curVis,grp)) return false;
            else if(curVis[cld]) return false;
        }
        curVis[i] = 0;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> grp[n];
        for(auto &p: pre) grp[p[1]].push_back(p[0]);

        vector<int> vis(n, 0), curVis(n,0);
        
        for(int i=0; i<n; ++i){
            if(!vis[i] && !acyclic(i,vis,curVis,grp)) return false;
        }
        return true;
            
    }
};