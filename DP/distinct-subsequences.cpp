

// 1. rec + memo: O(n^3), O(n^2)
class Solution {
public:
    int rec(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        int n = s.size(), m = t.size();
        if(j == m) return 1;
        if(i == n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int cnt = 0;
        for(int k=i; k<n; ++k){
            if(s[k] == t[j]){
                cnt += rec(k+1, j+1, s, t, dp);   
            }                
        }
        return dp[i][j] = cnt;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return rec(0, 0, s, t, dp);
    }
};



// 2. Can optimise it: O(n^2), O(n^2) still giving TLE due to tight constraints
class Solution {
public:
    int rec(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        int n = s.size(), m = t.size();
        if(j == m) return 1;
        if(i == n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]){
            return rec(i+1, j+1, s, t, dp) + rec(i+1, j, s, t, dp);
        }
        else{
            return rec(i+1, j, s, t, dp);
        }
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return rec(0, 0, s, t, dp);
    }
};



// 3. 2D DP: O(n^2), O(n^2)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        // THIS IS VERY IMPORTANT TO USE DOUBLE AND THEN TYPECAST TO INT
        // LONG LONG IS ALSO GIVING THE OVERFLOW ERROR 
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
        
        for(int i=0; i<=n; ++i){
            dp[i][0] = 1;
        }
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};


// 4. 1D DP: O(n^2), O(n)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<double> prev(m+1, 0);
        vector<double> curr(m+1, 0);
        prev[0] = curr[0] = 1;
        
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }
                else{
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return (int)prev[m];
    }
};