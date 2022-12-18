

// 1.
// T.C.	O(N*N)
// S.C. O(1)

class Solution {
public:
    int f(int i, int j, string s){
        int n = s.size(), cnt = 0;
        while(i >=0 && j < n && s[i] == s[j]){
            i--;
            j++;
            cnt++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int ans = 0, n = s.size();
        for(int i=0; i<n; ++i){
        	// 		odd + even
            ans += f(i, i, s) + f(i, i+1, s);
        }
        return ans;
    }
};


// 2. 
// T.C.	O(N*N)
// S.C. O(N*N)

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0, n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // diagonal traversal
        for(int d=0; d<n; ++d){
            for(int i=0, j=d; i<n && j<n; ++i, j++){
                if(d == 0){
                    dp[i][j] = 1;
                    ans++;
                }
                else if(d == 1 && s[i] == s[j]){
                    dp[i][j] = 1;
                    ans++;
                }
                else if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};