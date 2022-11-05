

// modified binary search: O(logN), O(1)
// Intution: Simply dry these two cases
// 1. [2,2,2,0,2,2]
// 2. [2,2,0,2,2,2,2,2]
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1, m;
        while(l < r){  
            m = l + (r-l)/2;
            if(nums[m] == nums[r]){
                r--;
            }
            else if(nums[m] > nums[r]){
                l = m+1;
            }
            else{
                r = m;
            }
        }
        return nums[l];
    }
};