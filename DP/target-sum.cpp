

// 1. rec + memo:
// O(n*2*sum), O(n*2*sum)
class Solution {
public:
    int dfs(int i, int target, vector<int>& nums, map<pair<int,int>, int>& dp){
        if(i < 0) return target == 0;
        pair<int, int> p = make_pair(i, target);
        if(dp.find(p) != dp.end()) return dp[p];

        return dp[p] = dfs(i-1, target + nums[i], nums, dp) + dfs(i-1, target - nums[i], nums, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int, int>, int> dp;
        return dfs(n-1, target, nums, dp);
    }
};


// 2. rec + memo(optimised):
// O(n*(target+sum)/2), O(n*(target+sum)/2)
class Solution {
public:
    int dfs(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(i < 0) return target == 0;

        if(dp[i][target] != -1) return dp[i][target];
        dp[i][target] = 0;
        if(target >= nums[i]){
            dp[i][target] += dfs(i-1, target-nums[i], nums, dp);
        }
        dp[i][target] += dfs(i-1, target, nums, dp);
        return dp[i][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for(int e: nums) sum += e;
        target += sum;
        if(target % 2 || target < 0) return 0;
        target /= 2;

        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return dfs(n-1, target, nums, dp);
    }
};


// 3. Tabular DP: 
// O(n*(target+sum)/2), O((target+sum)/2)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for(int e: nums) sum += e;
        target += sum;
        if(target % 2 || target < 0) return 0;
        target /= 2;

        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);
        prev[0] = 1;
        for(int i=1; i<=n; ++i){
            for(int j=0; j<=target; ++j){
                curr[j] = 0;
                if(j >= nums[i-1]){
                    curr[j] += prev[j - nums[i-1]];
                }
                curr[j] += prev[j];
            }
            prev = curr;
        }
        return prev[target];
    }
};