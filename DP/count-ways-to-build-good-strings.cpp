


// rec + memo: O(high), O(high)
class Solution {
    int mod = 1e9 + 7;
public:
    int rec(int len, int l1, int l2, vector<int>& dp){
        if(len < 0) return 0;
        if(len == 0) return 1;
        
        if(dp[len] != -1) return dp[len];
        return dp[len] = (rec(len-l1, l1, l2, dp) + rec(len-l2, l1, l2, dp)) % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        vector<int> dp(high+1, -1);
        for(int len = low; len <= high; ++len){
            ans = (ans + rec(len, one, zero, dp)) % mod;
        }
        return ans;
    }
};