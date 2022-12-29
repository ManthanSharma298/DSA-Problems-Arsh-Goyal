

// a great problem for DP optimisation: O(N*K), O(N*K) 
class Solution {
    int mod = 1e9 + 7;
public:
    ll exp(ll a, ll b){
        ll res = 1;
        while(b){
            if(b&1) res = (res*a)%mod;
            a = (a*a)%mod;
            b /= 2;
        }
        return res;
    }
    int knapsack(vector<int>& nums, int k){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for(int i=0; i<=n; ++i){
            for(int j=0; j<=k; ++j){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 0){
                    continue;
                }
                else if(j == 0){
                    dp[i][j] = 1;
                }
                else{
                    if(nums[i-1] <= j){
                        dp[i][j] = (dp[i-1][j - nums[i-1]] + dp[i-1][j]) % mod;
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        int ans = 0;
        for(int j=0; j<=k; ++j){
            ans = (ans + dp[n][j]) % mod;
        }
        return ans;
    }
    int countPartitions(vector<int>& nums, int k) {
        // x + y + z = 2^n
        // x + 2y = 2^n
        // x = 2^n - 2y
        int n = nums.size(), sm = 0;
        for(int &num: nums){
            sm = (sm + num) % mod;
        }
        if(sm < 2*k) return 0;
        int y = knapsack(nums, k-1), p = exp(2, n);
        p = (p - (2*y) % mod + mod) % mod;
        return p;
    }
};