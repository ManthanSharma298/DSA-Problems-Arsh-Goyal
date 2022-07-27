

// don't need to store them in queue as one node can have either 1 or 2 childs: O(E+N+N), O(N)
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> g;
        for(auto e: adjacentPairs){
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int prev, curr;
        vector<int> res;
        for(auto e: g){
            if(e.second.size() == 1){
                prev = e.first;
                curr = e.second[0];
                break;
            }
        }
        while(true){
            res.push_back(prev);
            prev = curr;
            
            if(g[curr].size() == 1){
                res.push_back(curr);
                break;
            }
            int f = g[curr][0], s = g[curr][1];

            curr = (f == res.back() ? s : f);
        }
        return res;
    }
};