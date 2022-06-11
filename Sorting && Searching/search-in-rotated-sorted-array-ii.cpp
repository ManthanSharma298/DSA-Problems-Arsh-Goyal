

// Binary Search + linear decrement: O(logn + n), O(1)
// worst case -> O(n)
// best case -> O(logn)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1, m;
        while(l < r){
            while(l < r && nums[l] == nums[r]) r--;
            m = l + (r-l)/2;
            if(nums[l] <= nums[m]){
                if(nums[l] <= target && target <= nums[m]){
                    r = m;  
                }
                else{
                    l = m+1;
                }
            }
            else{
                if(target < nums[l] && target > nums[m]) l = m+1;
                else r = m; 
            }
        }
        return nums[l] == target;
    }
};