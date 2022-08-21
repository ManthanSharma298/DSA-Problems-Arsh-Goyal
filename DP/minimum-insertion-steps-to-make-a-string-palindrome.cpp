

// recursion: O(2^n), O(n)
// as in worst case every step have 2 choices 
class Solution {
public:
    int rec(int l, int r, string& s){
        if(l >= r) return 0; 
        if(s[l] == s[r]) return rec(l+1, r-1, s);
        return min(rec(l+1, r, s), rec(l, r-1, s)) + 1;
    }
    int minInsertions(string s) {
        return rec(0, s.size()-1, s);
    }
};


// 2. 2d DP: O(n^2), O(n^2)
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+2, vector<int>(n+1, INT_MAX));
        
        for(int i=0; i<n+1; ++i){
            dp[i][0] = dp[0][i] = 0;
            dp[n+1][i] = 0;
        }
        
        for(int i=n; i>=1; --i){
            for(int j=1; j<=n; ++j){
                if(i >= j) dp[i][j] = 0;
                else if(s[i-1] == s[j-1]) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
            }
        }
        return dp[1][n];
    }
};