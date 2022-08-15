

// Swapping and check: O(N!*N), O(N)
class Solution {
    int cnt = 0;
public:
    void rec(int i, vector<int>& nums){
        if(i == nums.size()) cnt++;
        for(int j=i; j<nums.size(); ++j){
            if(nums[j] % (i+1) == 0 || (i+1) % nums[j] == 0){
                swap(nums[i], nums[j]);
                rec(i+1, nums);
                swap(nums[i], nums[j]);
            }
        }
    }
    int countArrangement(int n) {
        vector<int> nums(n);
        for(int i=0; i<n; ++i) nums[i] = i+1;
        rec(0, nums);
        return cnt;
    }
};