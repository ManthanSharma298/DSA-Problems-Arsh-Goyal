

// O(N*N), O(N*N)
#define ll long long 
class Solution{
    public:
    
    const ll mod = 1e9+7;
    long long int  countPS(string str){
        ll n = str.size();
        vector<vector<ll>> dp(n+2, vector<ll>(n+2, 0));
        
        for(int i=1; i<=n; ++i){
            dp[i][i] = 1;
        }
        int d = 0;
        for(int d=1; d<n; ++d){
            for(int i=1; i<=n-d; ++i){
                int j = i+d;
                if(str[i-1] == str[j-1]){
                    dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1)%mod;
                }
                else{
                	// VERY IMPORTANT STEP IN MOD
                	// whenever you have to subtract in mod then always add mod to it
                	// otherwise you wil get -ve answer
                    dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + mod)%mod;
                }
            }
        }
        return dp[1][n];
    }
     
};