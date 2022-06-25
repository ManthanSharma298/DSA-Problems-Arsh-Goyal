

// 1. BFS: O(2*r*c), O(r*c)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int lev = -1, f = 0, r = grid.size(), c = grid[0].size();
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        vector<int> dir[] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(auto &d: dir){
                    int xx = x+d[0], yy = y+d[1];
                    if(xx>=0 && xx<r && yy>=0 && yy<c && grid[xx][yy] == 1){
                        q.push({xx, yy});
                        grid[xx][yy] = 2;
                    }
                }
            }
            lev++;
        }
        int tw = 0;
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(grid[i][j] == 1) return -1;
                if(grid[i][j] == 2 && tw == 0) tw = 1;
            }
        }
        // if opnly zeros are present
        if(tw == 0) return 0;
        return lev;
    }
};

// 1.1 One run BFS: O(r*c), O(r*c)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int one = 0, lev = -1, f = 0, r = grid.size(), c = grid[0].size();
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(grid[i][j] == 1) one++;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }
        vector<int> dir[] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(auto &d: dir){
                    int xx = x+d[0], yy = y+d[1];
                    if(xx>=0 && xx<r && yy>=0 && yy<c && grid[xx][yy] == 1){
                        q.push({xx, yy});
                        grid[xx][yy] = 2;
                        one--;
                    }
                }
            }
            lev++;
        }
        // if 1 remains
        if(one > 0) return -1;
        // if opnly zeros are present
        if(lev == -1) return 0;
        // else
        return lev;
    }
};
