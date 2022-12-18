


// 1. DFS
// T.C. O(M*N)
// S.C. O(M*N)
class Solution {
public:
    
    int dfs(int i, int j, vector<vector<int>>& grid){
        int r = grid.size(), c = grid[0].size(), area;
        // condition
        if(grid[i][j] == 1){
            grid[i][j] = 0;     // mark it as visited
            area = 1;
            if(i+1 < r){
                area += dfs(i+1, j, grid);
            }
            if(i-1 >= 0){
                area += dfs(i-1, j, grid);
            }
            if(j+1 < c){
                area += dfs(i, j+1, grid);
            }
            if(j-1 >= 0){
                area += dfs(i, j-1, grid);
            }
            return area;
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, r = grid.size(), c = grid[0].size();
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }
        return maxArea;
    }
};

// 2. BFS
// T.C. O(M*N)
// S.C. O(M*N)
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), r = grid.size(), c = grid[0].size(), ans = 0, curr;
        queue<vector<int>> q;
        
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(grid[i][j] == 1){
                    q.push({i, j, 1});
                    grid[i][j] = 0;

                    curr = 0;
                    while(!q.empty()){
                        int i = q.front()[0], j = q.front()[1];
                        q.pop();
                        
                        curr++;
                        for(auto d: dir){
                            int x = d[0] + i, y = d[1] + j;
                            if(x >= 0 && y >= 0 && x < r && y < c && grid[x][y] == 1){
                                q.push({x, y});
                                grid[x][y] = 0;
                            }
                        }
                        ans = max(ans, curr);
                    }
                }
            }
        }
        
        return ans;
    }
};