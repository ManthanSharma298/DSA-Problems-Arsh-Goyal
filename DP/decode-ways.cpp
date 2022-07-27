

// recursive: O(2^n)
// Gives TLE
class Solution {
public:
    int rec(int id, string s){
        int n = s.size();
        if(id < 0) return 1;
        
        int cnt = 0;
        // take single elem
        if(s[id] != '0'){
            cnt += rec(id-1, s);
        }
        // take two elements
        if(id-1 >= 0 && (s[id-1] == '1' || (s[id-1] == '2' && s[id] >= '0' && s[id] <= '6') )){
            cnt += rec(id-2, s);
        }
        return cnt;
    }
    
    int numDecodings(string s) {
        return rec(s.size()-1, s);
    }
};


// 1d DP: O(n), O(n)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        
        for(int i=1; i<=n; ++i){
            if(s[i-1] != '0'){
                dp[i] += dp[i-1];
            }
            if(i-2 >= 0 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] >= '0' && s[i-1] <= '6') ) ){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};