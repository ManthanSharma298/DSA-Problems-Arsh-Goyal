

// 2d DP: O(m*n), O(m*n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int mx = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(mat[i][j] == '1'){
                    dp[i][j] = 1;
                    if(mx == 0) mx = 1;
                }
            }
        }
        
        for(int i=m-2; i>=0; --i){
            for(int j=n-2; j>=0; --j){
                if(dp[i][j] == 1){
                    dp[i][j] = min({dp[i][j+1], dp[i+1][j+1], dp[i+1][j]}) + 1;
                }
                mx = max(mx, dp[i][j]);
            }
        }
        
        return mx*mx;
    }
};

// 1d DP: 
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int mx = 0;

        vector<int> nxt(n, 0);
        vector<int> curr(n, 0);
        
        for(int j=0; j<n; ++j){
        	if(mat[m-1][j] == '1'){
        		nxt[j] = 1;
        		mx = 1;
        	}
        }
        
        for(int i=m-2; i>=0; --i){
        	if(mat[i][n-1] == '1'){
                curr[n-1] = 1;
                mx = max(mx, 1);
            }
            // Important to update curr
            else{
                curr[n-1] = 0;
            }
            for(int j=n-2; j>=0; --j){
                if(mat[i][j] == '1'){
                    curr[j] = min({curr[j+1], nxt[j+1], nxt[j]}) + 1;
                }
                else{
                    curr[j] = 0;
                }
                mx = max(mx, curr[j]);
            }
            
            nxt = curr;
        }
        
        return mx*mx;
    }
};