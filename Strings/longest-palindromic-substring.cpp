

// 1. count even and odd seperately: O(N^2), O(1) -> excluding res
class Solution {
public:
    string longestPalindrome(string s) {
        // odd lengths
        string res = "";
        int mx = 0;
        int n = s.size();
        for(int i=0; i<n; ++i){
            int l = i, r = i;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    l--;
                    r++;
                }
                else break;
            }
            l++;
            r--;
            if(mx < r-l+1){
                mx = r-l+1;
                res = s.substr(l, r-l+1);
            }
        }
        // even lengths
        for(int i=0; i<n-1; ++i){
            int l = i, r = i+1;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    l--;
                    r++;
                }
                else break;
            }
            l++;
            r--;
            if(mx < r-l+1){
                mx = r-l+1;
                res = s.substr(l, r-l+1);
            }
        }
        return res;
    }
};


// 2. DP: O(N*N), O(N*N)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        string ans = "";
        for(int d=0; d<n; ++d){
            for(int i=0, j=d; i<n && j<n; ++i, ++j){
                if(d == 0){
                    dp[i][j] = 1;
                }
                else if(d == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = 1;
                    }
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = 1;
                    }
                }
                if(ans.size() < d+1 && dp[i][j]){
                    ans = s.substr(i, j-i+1);
                }
            }
        }
        return ans;
    }
};