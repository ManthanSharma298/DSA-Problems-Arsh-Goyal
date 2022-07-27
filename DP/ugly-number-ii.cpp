

// DP: O(n), O(n)
class Solution {
public:
    int nthUglyNumber(int n) {
        int f=0, s=0, t=0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        int mn;
        int i = 1;
        while(i < n){
            mn = min({2*dp[f], 3*dp[s], 5*dp[t]});
            if(mn == 2*dp[f]) f++;
            if(mn == 3*dp[s]) s++;
            if(mn == 5*dp[t]) t++;
            
            dp[i++] = mn;
        }
        return dp[n-1];
    }
};