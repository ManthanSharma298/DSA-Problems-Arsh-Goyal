


// Brute force: O(number_of_zeros*n*n) ~ O(N^4), O(N^2) 
// gives TLE  
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int area = 1;
        
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(auto v: dir){
            int x = i+v[0], y = j+v[1];
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && vis[x][y] == 0 && grid[x][y] == 1){
                vis[x][y] = 1;
                area += dfs(x, y, vis, grid);
            }
        }
        return area;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int mx = 0, f = 0;
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(grid[i][j] == 0){
                    f = 1;
                    vector<vector<int>> vis(r, vector<int>(c, 0));
                    mx = max(mx, dfs(i, j, vis, grid));
                }
            }
        }
        if(f == 0) mx = r*c;
        return mx;
    }
};


// Don't know why leetcode is giving TLE now they will accept Union-find approach
// 
class Solution {
    unordered_map<int,int> id;
public:
    int dfs(int i, int j, int cnt, vector<vector<int>>& grid){
        int area = 1;
        
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(auto v: dir){
            int x = i+v[0], y = j+v[1];
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y] == 1){
                grid[x][y] = cnt;
                area += dfs(x, y, cnt, grid);
            }
        }
        return area;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        
        int cnt = 2, mx = 0;
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(grid[i][j] == 1){
                    grid[i][j] = cnt;
                    int x = i, y = j;
                    int size = dfs(i, j, cnt, grid);
                    id.insert({cnt, size});
                    mx = max(mx, id[cnt]);
                    cnt++;
                }
            }
        }
        int curr;
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(grid[i][j] == 0){
                    curr = 1;
                    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
                    int x, y;
                    unordered_set<int> st;
                    for(auto v: dir){
                        x = i+v[0], y = j+v[1];
                        if(x>=0 && x<r && y>=0 && y<c && grid[x][y] != 0){
                            st.insert(grid[x][y]);
                        }
                    }
                    for(auto it = st.begin(); it != st.end(); ++it){
                        auto itr = id.find(*it);
                        curr += itr->second;
                    }
                    mx = max(mx, curr);
                }
            }
        }
        return mx;
    }
};