

// 1. Recusion + memoization: O(n), O(n)
class Solution
{
    public:
    int rec(int n, int x, int y, int z, vector<int> &dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
    
        int cnt = INT_MIN;
    
        if(n >= x) cnt = max(cnt, rec(n-x,x,y,z,dp));
        if(n >= y) cnt = max(cnt, rec(n-y,x,y,z,dp));
        if(n >= z) cnt = max(cnt, rec(n-z,x,y,z,dp));
        
        if(cnt == INT_MIN){
            return dp[n] = cnt;
        } 
        return dp[n] = cnt+1;
    }
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1, -1);
        int res = rec(n,x,y,z, dp);
        if(res == INT_MIN) return 0;
        return res;
    }
};

// 2. DP: O(n), O(n)
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1, INT_MIN);
        dp[0] = 0;

        for(int i=1; i<=n; ++i){
            if(i-x >= 0) dp[i] = max(dp[i], dp[i-x]);
            if(i-y >= 0) dp[i] = max(dp[i], dp[i-y]);
            if(i-z >= 0) dp[i] = max(dp[i], dp[i-z]);

            if(dp[i] != INT_MIN) dp[i]++;
        }
        // IMPORTANT STEP IN INTERVIEW
        return (dp[n] == INT_MIN ? 0 : dp[n]);
    }
};