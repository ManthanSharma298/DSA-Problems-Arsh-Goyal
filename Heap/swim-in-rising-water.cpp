

// 1. O(r*c*log(r*c)), O(r*c)
class Solution {
public:
    // min heap -> min element comes at last position
    // means decreasing order
    struct cmp{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[2] > b[2]; 
        }  
    };
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        pq.push({0, 0, grid[0][0]});
        vis[0][0] = 1;
        
        vector<vector<int>> dist = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            
            int x = tp[0], y = tp[1], lev = tp[2];
            if(x == n-1 && y == n-1) return lev;
            for(auto ax: dist){
                int xx = x+ax[0], yy = y+ax[1];
                if(xx >= 0 && xx < n && yy >= 0 && yy < n && vis[xx][yy] == 0){
                    pq.push({xx, yy, max(grid[xx][yy], lev)});
                    vis[xx][yy] = 1;
                }
            }
        }
        return 0;
    }
};


// 2. Binary Search: 