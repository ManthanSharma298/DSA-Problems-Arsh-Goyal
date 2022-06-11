// 1. Brute force: O(n**3), O(1)

// 2. Sorting: O(nlogn), O(logn)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size(), res, curr;
        sort(nums.begin(), nums.end());
        
        return max(nums[0]*nums[1]*nums[n-1], nums[n-1]*nums[n-2]*nums[n-3]);
    }
};
