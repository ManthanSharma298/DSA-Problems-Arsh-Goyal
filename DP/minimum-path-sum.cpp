

// 2d DP: O(r*c), O(r*c)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> dp(r+1, vector<int>(c+1, 0));
        for(int i=1; i<=r; ++i){
            dp[i][1] = dp[i-1][1] + grid[i-1][0];
        }
        for(int j=1; j<=c; ++j){
            dp[1][j] = dp[1][j-1] + grid[0][j-1];
        }
        for(int i=2; i<=r; ++i){
            for(int j=2; j<=c; ++j){
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i-1][j-1];
            }
        }
        return dp[r][c];
    }
};