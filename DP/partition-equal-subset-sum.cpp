

// 0-1 knapsack: O(n*k), O(k+k)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int k = 0;
        for(int e: nums) k += e;
        
        if(k%2) return false;
        k /= 2;
        
        vector<bool> prev(k+1, false);
        vector<bool> curr(k+1, false);

        int n = nums.size();
        for(int i=1; i<=n; ++i){
            prev[0] = true;
            for(int j=0; j<=k; ++j){
                bool in = false, ex = false;
                if(j >= nums[i-1]){
                    in = prev[j-nums[i-1]];
                }
                ex = prev[j];
                curr[j] = in || ex;
            }
            prev = curr;
        }
        return prev[k];
        
    }
};