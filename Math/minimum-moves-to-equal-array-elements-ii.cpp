
// difference: O(n), O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        int t = nums[n/2];
        
        for(int e: nums){
            cnt += abs(t - e);
        }
        
        return cnt;
    }
};