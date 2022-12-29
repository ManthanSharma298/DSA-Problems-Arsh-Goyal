


// 1. DP: O(N*nums[i]), O(N)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = 0;
        for(int i=n-2; i>=0; --i){
            int mn = n;
            for(int j=i+1; j<=i+nums[i] && j<n; j++){
                if(dp[j] != -1){
                    mn = min(mn, 1 + dp[j]);
                }
            }
            dp[i] = mn;
        }      
        return dp[0];
    }
};


// 2. BFS: O(N), O(N)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        queue<int> q;
        vector<int> vis(n, 0);
        vis[0] = 1;
        q.push(0);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int i = q.front(), j = i+1;
                q.pop();

                while(j < n && j <= i+nums[i]){
                    if(!vis[j]){
                        q.push(j);
                        vis[j] = 1;
                    }
                    j++;
                }
            }
            cnt++;
        }   
        return cnt-1;
    }
};