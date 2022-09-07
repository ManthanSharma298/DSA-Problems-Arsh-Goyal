


// 1. rec + memo: O(n^3), O(n^2)
int rec(int i, int j, vector<int>& keys, vector<int>& freq, vector<vector<int>>& dp){
    if(i > j) return 0;
    if(i == j) return freq[i];
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int mn = 1e9, sm = 0;
    for(int id = i; id <= j; ++id){
        sm += freq[id];
    }
    for(int id=i; id<=j; ++id){
        int lf = rec(i, id-1, keys, freq, dp);
        int rt = rec(id+1, j, keys, freq, dp);
        
        mn = min(mn, lf+rt+sm);
    }
    return dp[i][j] = mn;
}
int optimalCost(vector<int>& keys, vector<int>& freq, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return rec(0, n-1, keys, freq, dp);
}