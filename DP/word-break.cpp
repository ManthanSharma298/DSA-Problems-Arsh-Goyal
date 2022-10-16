

// using l, r index or 2D DP
class Solution {
public:
    int f(int l, int r, string s, unordered_set<string>& st, vector<vector<int>>& dp){
        if(l > r) return 1;
        
        if(dp[l][r] != -1) return dp[l][r];
        for(int i=l; i<=r; ++i){
            // l to i
            string ss = s.substr(l, i-l+1);
            if(st.find(ss) != st.end()){
                if(f(i+1, r, s, st, dp)) return dp[l][r] = 1;
            }
        }
        return dp[l][r] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(string s: wordDict){
            st.insert(s);
        }
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int res = f(0, s.size()-1, s, st, dp);
        
        if(res == 1) return true;
        return false;
    }
};


// 2. Using 1D DP:
class Solution {
public:
    int f(int l, string s, unordered_set<string>& st, vector<int>& dp){
        if(l >= s.size()) return 1;
        
        if(dp[l] != -1) return dp[l];

        string curr = "";
        for(int i=l; i<=s.size(); ++i){
            curr += s[i];
            
            if(st.find(curr) != st.end()){
                if(f(i+1, s, st, dp)) return dp[l] = 1;
            }
        }
        return dp[l] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(string s: wordDict){
            st.insert(s);
        }
        int n = s.size();
        vector<int> dp(n, -1);
        int res = f(0, s, st, dp);
        
        if(res == 1) return true;
        return false;
    }
};