
// Update the max reach: O(n) O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), reach = n-1;
        for(int i=n-2; i>=1; --i){
            if(i + nums[i] >= reach) reach = i;
        }
        if(nums[0] >= reach) return true;
        return false;
    }
};