

// Time Complex: O(3*row*col)
// Space Complx: O(2*row*col) 
class Solution {
public:
    void dfs(int i, int j, int prev, vector<vector<bool>>& vis, vector<vector<int>>& heights){
        int row = vis.size(), col = vis[0].size();
        if(i < 0 || j < 0 || i >= row || j >= col || heights[i][j] < prev || vis[i][j]) return;
        
        vis[i][j] = true;
        dfs(i+1, j, heights[i][j], vis, heights);
        dfs(i-1, j, heights[i][j], vis, heights);
        dfs(i, j+1, heights[i][j], vis, heights);
        dfs(i, j-1, heights[i][j], vis, heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<bool>> pac(row, vector<bool>(col, false));
        vector<vector<bool>> atl(row, vector<bool>(col, false));
        
        for(int i=0; i<row; ++i){
            dfs(i, 0, INT_MIN, pac, heights);
            dfs(i, col-1, INT_MIN, atl, heights);
        }
        for(int j=0; j<col; ++j){
            dfs(0, j, INT_MIN, pac, heights);
            dfs(row-1, j, INT_MIN, atl, heights);
        }
        
        vector<vector<int>> ans;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(atl[i][j] && pac[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};