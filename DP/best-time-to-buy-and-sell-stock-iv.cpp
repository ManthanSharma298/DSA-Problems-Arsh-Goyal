

// we can also use 3d vector(faster) but here I have used map
// rec + memo: O(n*2*k), O(n*2*k)
class Solution {
    map<vector<int>, int> dp;
public:
    int rec(int i, int canBuy, int k, vector<int>& prices){
        if(i == prices.size() || k == 0) return 0;
        
        auto it = dp.find({i, canBuy, k});
        if(it != dp.end()){
            return it->second;
        }
        
        int buy, sell, leave, mx = 0;
        if(canBuy == 1){
            buy = -prices[i] + rec(i+1, 0, k, prices);
            leave = rec(i+1, 1, k, prices);
            mx = max(mx, max(buy, leave));
        }
        else{
            sell = prices[i] + rec(i+1, 1, k-1, prices);
            leave = rec(i+1, 0, k, prices);
            mx = max(mx, max(sell, leave));
        }
        
        dp[{i, canBuy, k}] = mx;
        return mx;
    }
    int maxProfit(int k, vector<int>& prices) {
        return rec(0, 1, k, prices);
    }
};


// Tabular DP: O(n*2*k), O(n*2*k)
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
    
    for(int i=n-1; i>=0; --i){
        for(int j=0; j<2; ++j){
            for(int kk=1; kk<=k; ++kk){
                if(j == 1){
                    int buy = -prices[i] + dp[i+1][0][kk];
                    int leave = dp[i+1][1][kk];
                    
                    dp[i][j][kk] = max(dp[i][j][kk], max(buy, leave));
                }
                else{
                    int sell = prices[i] + dp[i+1][1][kk-1];
                    int leave = dp[i+1][0][kk];
                    
                    dp[i][j][kk] = max(dp[i][j][kk], max(sell, leave));
                }
            }
        }
    }
    
    return dp[0][1][k];
}