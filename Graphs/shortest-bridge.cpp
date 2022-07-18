

// IMPORTANT THING IS DON'T PUSH MORE ELEMENTS IN QUEUE 
// CODE GIVING TLE
class Solution {
    queue<pair<int,int>> q;
public:
    void dfs(int i, int j, vector<vector<int>> &grid){
        grid[i][j] = 2;
        q.push({i, j});
        int n = grid.size();
        vector<int> dir[] = {{0,1},{1,0},{-1,0},{0,-1}};
        
        for(int k=0; k<4; ++k){
            int x = i+dir[k][0], y = j+dir[k][1];
            if(x>=0 && x<n && y>=0 && y<n && grid[x][y] == 1){
                dfs(x, y, grid);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int f = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == 1){
                    dfs(i, j, grid);
                    f = 1;
                    break;
                }
            }
            if(f) break;
        }
        vector<int> dir[] = {{0,1},{1,0},{-1,0},{0,-1}};
        int cnt = -1;
        
        while(!q.empty()){
            int sz = q.size();
            for(int j=0; j<sz; ++j){
                auto p = q.front();
                q.pop();
                // IT IS BAD TO CHECK HERE THIS WILL GIVE TLE
                if(grid[p.first][p.second] == 1){
                    return cnt;
                }
                grid[p.first][p.second] = 2;
                for(int k=0; k<4; ++k){
                    int x = p.first+dir[k][0], y = p.second+dir[k][1];
                    if(x>=0 && x<n && y>=0 && y<n && grid[x][y] != 2){
                        q.push({x, y});
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};


// Optimized code: O(N**2 + N**2), O(N**2)
class Solution {
    queue<pair<int,int>> q;
public:
    void dfs(int i, int j, vector<vector<int>> &grid){
        grid[i][j] = 2;
        q.push({i, j});
        int n = grid.size();
        vector<int> dir[] = {{0,1},{1,0},{-1,0},{0,-1}};
        
        for(int k=0; k<4; ++k){
            int x = i+dir[k][0], y = j+dir[k][1];
            if(x>=0 && x<n && y>=0 && y<n && grid[x][y] == 1){
                dfs(x, y, grid);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int f = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == 1){
                    dfs(i, j, grid);
                    f = 1;
                    break;
                }
            }
            if(f) break;
        }
        vector<int> dir[] = {{0,1},{1,0},{-1,0},{0,-1}};
        int cnt = -1;
        
        while(!q.empty()){
            int sz = q.size();
            for(int j=0; j<sz; ++j){
                auto p = q.front();
                q.pop();
                
                for(int k=0; k<4; ++k){
                    int x = p.first+dir[k][0], y = p.second+dir[k][1];
                    if(x>=0 && x<n && y>=0 && y<n && grid[x][y] != 2){
                        if(grid[x][y] == 1){
                            return cnt+1;
                        }
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
            cnt++;
        }
        
        return -1;
    }
};