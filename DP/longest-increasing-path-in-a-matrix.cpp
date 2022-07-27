

// rec + memo: O(m*n), O(m*n)
class Solution {
public:
    int rec(int i, int j, int prev, vector<vector<int>>& dp, vector<vector<int>>& matrix){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || prev >= matrix[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];    
        
        int cnt = 1;
        cnt = max(cnt, rec(i+1, j, matrix[i][j], dp, matrix) + 1);
        cnt = max(cnt, rec(i, j+1, matrix[i][j], dp, matrix) + 1);
        cnt = max(cnt, rec(i-1, j, matrix[i][j], dp, matrix) + 1);
        cnt = max(cnt, rec(i, j-1, matrix[i][j], dp, matrix) + 1);
        
        return dp[i][j] = cnt;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int mx = 1;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(dp[i][j] == -1){
                    rec(i, j, -1, dp, matrix);
                }
                mx = max(mx, dp[i][j]);
            }
        }
        return mx;   
    }
};
