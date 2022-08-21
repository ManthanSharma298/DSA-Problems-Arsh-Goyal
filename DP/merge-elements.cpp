

// 1. rec + memo: O(n*n), O(n*n)
// if you don't get the time complexity of rec+memo then write that of dp solution 

int rec(int l, int r, vector<int>& A, vector<vector<int>>& dp){
    if(r-l == 0) return 0;
    int mn = INT_MAX;
    // spliting into 2 parts
    if(dp[l][r] != -1) return dp[l][r];
    int sm = 0;
    for(int k=l; k<=r; ++k) sm += A[k];
    for(int k=l+1; k<=r; ++k){
        mn = min(mn, sm + rec(l, k-1, A, dp) + rec(k, r, A, dp));
    }
    return dp[l][r] = mn;
}
int Solution::solve(vector<int> &A) {
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), -1));
    return rec(0, A.size()-1, A, dp);
}


// 2. 2d DP: O(n*n), O(n*n)

int Solution::solve(vector<int> &A) {
	int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    
    for(int i=0; i<n; ++i) dp[i][i] = 0;

    for(int i=n-1; i>=0; --i){
    	for(int j=i+1; j<=n-1; ++j){
    		int sm = 0;
    		for(int k=i; k<=j; ++k) sm += A[k];
    		for(int k=i+1; k<=j; ++k){
    			dp[i][j] = min(dp[i][j], sm + dp[i][k-1] + dp[k][j]);
    		}
    	}
    }
    return dp[0][n-1];
}