

// 2d DP: O(n*amt), O(n*amt)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 1e9));
        
        for(int i=0; i<=n; ++i){
            dp[i][0] = 0;
        }
        
        for(int i=1; i<=n; ++i){
            for(int sm=1; sm<=amount; ++sm){
                if(sm - coins[i-1] >= 0){
                    dp[i][sm] = min(dp[i][sm - coins[i-1]] + 1, dp[i-1][sm]);
                }
                else{
                    dp[i][sm] = dp[i-1][sm];
                }
            }
        }
        
        return dp[n][amount] == 1e9 ? -1 : dp[n][amount];
    }
};


// 1d DP: O(n*amt), O(2*amt)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 1e9);
        vector<int> curr(amount+1, 1e9);

        prev[0] = 0;
        curr[0] = 0;
        
        for(int i=1; i<=n; ++i){
            for(int sm=1; sm<=amount; ++sm){
                if(sm - coins[i-1] >= 0){
                    curr[sm] = min(curr[sm - coins[i-1]] + 1, prev[sm]);
                }
                else{
                    curr[sm] = prev[sm];
                }
            }
            prev = curr;
        }
        
        return prev[amount] == 1e9 ? -1 : prev[amount];
    }
};
