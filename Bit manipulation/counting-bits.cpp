

// 1. Brute force: O(n*logn), O(1) -> excluding vector
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; ++i){
            int dig = i, cnt = 0;
            while(dig > 0){
                cnt += dig%2;
                dig /= 2;
            }
            dp[i] = cnt;
        }
        return dp;
    }
};


// 2. bits and DP: O(n), O(1) -> excluding vector
class Solution {
public:
    vector<int> countBits(int n) {
  		vector<int> dp(n+1, 0);
  		int p = 1;
  		for(int i=1; i<=n; ++i){
  			if(i == p){
  				dp[i] = 1;
  				p *= 2;
  			}
  			else{
  				dp[i] = dp[p/2] + dp[i - p/2];
  			}
  		}      
  		return dp;
    }
};