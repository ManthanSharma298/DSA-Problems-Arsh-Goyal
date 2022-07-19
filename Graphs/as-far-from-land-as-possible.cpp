

// There are two ways to apply bfs in this problem
// 1.1 BFS: O(r*c + r*c), O(r*c)
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int mx = -1, r = grid.size(), c = grid[0].size();
        queue<pair<int, int>> q;
        
        int fg = 0;
        for(int x=0; x<r; ++x){
            for(int y=0; y<c; ++y){
                if(grid[x][y] == 1){
                    q.push({x, y});
                    grid[x][y] = 0;
                }
                else{
                    if(fg == 0) fg = 1;
                    grid[x][y] = -1;
                }
            }
        }
        if(!fg) return -1;
        
        int dist = -1;
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; ++i){
                int x = q.front().first, y = q.front().second;
                q.pop();
                
                for(auto &d: dir){
                    int xi = x + d[0], yi = y + d[1];
                    if(xi >= 0 && xi < r && yi >= 0 && yi < c && grid[xi][yi] == -1){
                        q.push({xi, yi});
                        grid[xi][yi] = 0;
                    }
                }
            }
            dist++;
        }
        return dist;
    }
};


// 1.2 BFS: O(r*c + r*c), O(r*c)
#define mkp make_pair 

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == 1){
                    q.push(mkp(i,j));
                }
            }
        }
        int mx = -1;
        int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
        while(!q.empty()){
            auto pr = q.front();
            q.pop();
            int x=pr.first, y=pr.second,xx,yy;
            
            for(int i=0; i<4; ++i){
                xx=x+dx[i], yy=y+dy[i];
                if(xx>=0 && yy>=0 && xx<n && yy<n && grid[xx][yy] == 0) {
                    q.push(mkp(xx,yy));
                    grid[xx][yy] = grid[x][y]+1;
                    mx = max(mx, grid[xx][yy]-1);
                }
            }
        }
        return mx;
    }
};