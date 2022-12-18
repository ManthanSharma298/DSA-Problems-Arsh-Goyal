

// 1. rec + 3D DP
// O(n*m*k), O(n*m*k)
class Solution {
public:
    bool rec(int i, int j, int k, string a, string b, string c, vector<vector<vector<int>>>& dp){
        if(i == a.size() && j == b.size() && k == c.size()) return true;
        if(dp[i][j][k] != -1) return dp[i][j][k];

        if(i < a.size() && a[i] == c[k] && rec(i+1, j, k+1, a, b, c, dp)) return dp[i][j][k] = true;
        if(j < b.size() && b[j] == c[k] && rec(i, j+1, k+1, a, b, c, dp)) return dp[i][j][k] = true;

        return dp[i][j][k] = false;
    } 
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>> dp(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1, -1)));
        return rec(0, 0, 0, s1, s2, s3, dp);
    }
};


// 2. rec + 2D DP
// O(n*m), O(n*m)
class Solution {
public:
    bool rec(int i, int j, string a, string b, string c, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return true;
        if(dp[i][j] != -1) return dp[i][j];

        if(i >= 1 && a[i-1] == c[i+j-1] && rec(i-1, j, a, b, c, dp)) return dp[i][j] = true;
        if(j >= 1 && b[j-1] == c[i+j-1] && rec(i, j-1, a, b, c, dp)) return dp[i][j] = true;

        return dp[i][j] = false;
    } 
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return rec(s1.size(), s2.size(), s1, s2, s3, dp);
    }
};


// 3. rec + 2D Tabular 
// O(n*m), O(n*m)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));

        for(int i=0; i<=s1.size(); ++i){
            for(int j=0; j<=s2.size(); ++j){
            	// Base case 1
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }               
            	// Base case 2 
                else if(i == 0){
                    dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
            	// Base case 3
                else if(j == 0){
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                }
                // recursion
                else{
                    dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]) || (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};