

// DFS solution: O(r*c), O(r*c)
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image, int color, int newColor, set<pair<int,int>>& st){
        int r = image.size(), c = image[0].size();
        if(image[i][j] == color){
            image[i][j] = newColor;
            st.insert({i, j});
            if(j+1 < c && !st.count({i, j+1})){
                dfs(i, j+1, image, color, newColor, st);
            }
            if(j-1 >= 0 && !st.count({i, j-1})){
                dfs(i, j-1, image, color, newColor, st);
            }
            if(i+1 < r && !st.count({i+1, j})){
                dfs(i+1, j, image, color, newColor, st);
            }
            if(i-1 >= 0 && !st.count({i-1, j})){
                dfs(i-1, j, image, color, newColor, st);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        set<pair<int,int>>vis;
        dfs(sr, sc, image, color, newColor, vis);
        return image;
    }
};


// 2. BFS: O(r*c), O(r*c)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int ic = image[sr][sc];
        int r = image.size(), c = image[0].size();
        // BFS
        queue<pair<int,int>> q;
        image[sr][sc] = color;
        q.push({sr, sc});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int X = p.first, Y = p.second;
            vector<int> dir[] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
            for(auto el: dir){
                int x = el[0] + X;
                int y = el[1] + Y;
                if(x>=0 && x<r && y>=0 && y<c && image[x][y] == ic){
                    image[x][y] = color;
                    q.push({x, y});
                }
            }
        }
        return image;
    }
};