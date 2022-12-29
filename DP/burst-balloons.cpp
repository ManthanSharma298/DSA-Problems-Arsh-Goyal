

// rec + memo: O(n^3), O(n^2)
class Solution {
public:
    int rec(int i, int j, vector<int>& a, vector<vector<int>>& dp){
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int mx = INT_MIN, cost;
        for(int id=i; id<=j; ++id){
            // i-1 && j+1 act as boundaries for all elements from i to j
            cost = a[i-1]*a[id]*a[j+1] + rec(i, id-1, a, dp) + rec(id+1, j, a, dp);
            mx = max(mx, cost);
        }
        return dp[i][j] = mx;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n+2);
        a[0] = a[n+1] = 1;
        for(int i=1; i<=n; ++i){
            a[i] = nums[i-1];
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return rec(1, n, a, dp);
    }
};


class Solution {
public: 
    int dfs(int l, int r, vector<int>& a, vector<vector<int>>& dp){
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int mx = 0;
        for(int i=l+1; i<r; ++i){
            mx = max(mx, a[l]*a[i]*a[r] + dfs(l, i, a, dp) + dfs(i, r, a, dp));
        }
        return dp[l][r] = mx;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> a(n+2);
        a[0] = a[n+1] = 1;
        for(int i=0; i<n; ++i){
            a[i+1] = nums[i];
        }
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return dfs(0, n+1, a, dp);

    }
};