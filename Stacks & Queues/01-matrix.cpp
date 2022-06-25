

// reverse bfs(inserting 0's instead of 1's in queue): O(4*r*c), O(r*c)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int r = mat.size(), c = mat[0].size();
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = -1;
            }
        }
        vector<int> dist[] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for(auto &v: dist){
                int xx = x+v[0], yy = y+v[1];
                if(xx<r && xx>=0 && yy<c && yy>=0 && mat[xx][yy] == -1){
                    mat[xx][yy] = mat[x][y]+1;
                    q.push({xx, yy});
                }
            }
        }
        return mat;
    }
};

// DP: O(r*c), O(1)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // updating from left and top
        int r = mat.size(), c = mat[0].size(), mx = r+c;
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                int left = mx, top = mx;
                if(mat[i][j] == 0) continue;
                if(i-1 >= 0) top = mat[i-1][j]; 
                if(j-1 >= 0) left = mat[i][j-1];
                mat[i][j] = min(left, top)+1;
            }
        }
        // updating from bottom and right
        for(int i=r-1; i>=0; --i){
            for(int j=c-1; j>=0; --j){
                int bottom = mx, right = mx;
                if(mat[i][j] == 0) continue;
                if(i+1 < r) bottom = mat[i+1][j]; 
                if(j+1 < c) right = mat[i][j+1];
                mat[i][j] = min(mat[i][j], min(bottom, right)+1);
            }
        }
        return mat;
    }
};