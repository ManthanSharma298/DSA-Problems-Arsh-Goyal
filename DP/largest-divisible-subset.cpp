

// Similar to LIS: O(N*N), O(N+N)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), id = 0, mx = 1;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 0);
        vector<int> prev(n, 0);

        for(int i=0; i<n; ++i){
            dp[i] = 1;
            prev[i] = -1;
            for(int j=0; j<i; ++j){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j]+1){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if(dp[i] > mx){
                mx = dp[i];
                id = i;
            }
        }
        vector<int> ans;
        while(id != -1){
            ans.push_back(nums[id]);
            id = prev[id];
        }
        return ans;
    }
};