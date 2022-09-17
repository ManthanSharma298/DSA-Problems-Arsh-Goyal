

// rec + memo: O(n*k), O(n*k)
class Solution {
public:
    int mod = 1e9 + 7;
    int rec(int s, int e, int k, vector<vector<int>>& dp){
        if(k == 0){
            if(s == e) return 1;
            return 0;
        }
        if(dp[s][k] != -1) return dp[s][k];
        return dp[s][k] = (rec(s-1, e, k-1, dp) + rec(s+1, e, k-1, dp)) % mod;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3500, vector<int>(1002, -1));  
        return rec(startPos + 1000, endPos + 1000, k, dp);
    }
};