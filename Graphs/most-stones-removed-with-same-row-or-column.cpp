

// connected components: O(n), O(n+n)
class Solution {
public:
    void dfs(int i, vector<int>& vis, unordered_map<int, vector<int>>& x, unordered_map<int, vector<int>>& y, vector<vector<int>>& stones){
        int xc = stones[i][0], yc = stones[i][1];
        vis[i] = 1;
        
        for(int &id: x[xc]){
            if(vis[id] == 0){
                dfs(id, vis, x, y, stones);
            }
        }
        for(int &id: y[yc]){n
            if(vis[id] == 0){
                dfs(id, vis, x, y, stones);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> x;
        unordered_map<int, vector<int>> y;
        
        for(int i=0; i<stones.size(); ++i){
            auto stone = stones[i];
            x[stone[0]].push_back(i);
            y[stone[1]].push_back(i);
        }
        
        vector<int> vis(stones.size(), 0);
        
        int conec = 0;
        for(int i=0; i<stones.size(); ++i){
            auto stone = stones[i];
            if(vis[i] == 0){
                dfs(i, vis, x, y, stones);
                conec++;
            }
        }
        return stones.size() - conec; 
    }
};