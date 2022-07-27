

// DFS: O(n), O(n+n)
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