

// 2d-DP: O(10*n), O(10*n)
class Solution {
    int mod = 1e9+7;
public:
    int knightDialer(int n) {
        vector<int> dir[10] = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
        }; 
        
        vector<vector<int>> dp(10, vector<int>(n+1, 0));
        for(int i=0; i<10; ++i){
            dp[i][0] = 1;
        }
        
        for(int j=1; j<=n; ++j){
            for(int i=0; i<10; ++i){
                for(int &e: dir[i]){
                    dp[i][j] = (dp[i][j] + dp[e][j-1])%mod;
                }
            }
        }
    
        int res = 0;
        for(int i=0; i<10; ++i){
            res = (res + dp[i][n-1])%mod;
        }        
        return res;
    }
};

// 1d-DP: O(10*n), O(2*10) ~ O(k)
class Solution {
    int mod = 1e9+7;
public:
    int knightDialer(int n) {
        vector<int> dir[10] = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
        }; 
        
        vector<int> prev(10, 1);
        vector<int> curr(10, 0);
        
        for(int j=1; j<n; ++j){
            for(int i=0; i<10; ++i){
            	curr[i] = 0;
                for(int &e: dir[i]){
                    curr[i] = (curr[i] + prev[e])%mod;
                }
            }
            prev = curr;
        }
    
        int res = 0;
        for(int i=0; i<10; ++i){
            res = (res + prev[i])%mod;
        }        
        return res;
    }
};