

// rec + memo + binary search: O(n*k*logn), O(n*k)
// top-down
class Solution {
public:
    int f(int n, int k, vector<vector<int>>& dp){
        // base conditions
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int mn = INT_MAX;
        int l = 0, r = n, m;
        while(l+1 < r){
            m = l + (r-l)/2;
            int brk = f(m-1, k-1, dp);
            int nbrk = f(n-m, k, dp);
            
            if(brk < nbrk){
                // to go upward we need to increase m
                l = m;
            }
            else{
                r = m;
            }
            mn = min(mn, max(brk, nbrk) + 1);
        }
        return dp[n][k] = mn;
    }
    int superEggDrop(int k, int n){
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return f(n, k, dp);
    }
};


// DP(bottom-up): O(n*k*logn), O(n*k)
class Solution {
public:
    int superEggDrop(int k, int n){
        vector<vector<int>> dp(n+1, vector<int>(k+1, 1e9));

        for(int j=0; j<=k; ++j){
        	dp[0][j] = 0;
        	dp[1][j] = 1;
        }

        for(int i=0; i<=n; ++i){
        	dp[i][1] = i;
        }

        for(int i=2; i<=n; ++i){
        	for(int j=2; j<=k; ++j){
        		int l = 0, r = i, m;
		        while(l+1 < r){
		            m = l + (r-l)/2;
		            int brk = f(m-1, j-1, dp);
		            int nbrk = f(i-m, j, dp);
		            
		            if(brk < nbrk){
		                // to go upward we need to increase m
		                l = m;
		            }
		            else{
		                r = m;
		            }
		            dp[i][j] = min(dp[i][j], max(brk, nbrk) + 1);
		        }
        	}
        }
        return dp[n][k];
    }
};