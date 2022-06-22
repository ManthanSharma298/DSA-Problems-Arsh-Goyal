

// DP: O(n*n), O(n*n + n)
#include <algorithm>
int wordWrap(vector<string> words,int m,int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int curr;
    for(int i=0; i<n; ++i){
        curr = 0;
        for(int j=i; j<n; ++j){
            curr += words[j].size();
            if(curr + (j-i) > m) break;
            dp[i][j] = pow(m - curr - (j-i), 3);
        }
    }
    
    vector<int> mn(n, 1e9);
    
    for(int i=n-1; i>=0; --i){
        for(int j=n-1; j>=i; --j){
            if(dp[i][j] == -1) continue;
            curr = dp[i][j];
            if(j+1 < n) curr += mn[j+1];
            mn[i] = min(mn[i], curr);
        }
    }
    return mn[0];
}