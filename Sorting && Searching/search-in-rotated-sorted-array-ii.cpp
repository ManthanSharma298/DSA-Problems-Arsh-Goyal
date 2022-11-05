

// Binary Search + linear decrement: O(logn), O(1)
// worst case -> O(n)
// best case -> O(logn)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1, m;
        while(l <= r){
            m = l + (r-l)/2;
            if(nums[m] == target) return true;
            // if left half is sorted
            if(nums[l] == nums[m]){
                l++;
            }
            else if(nums[l] < nums[m]){
                if(target >= nums[l] && target <= nums[m]){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
            // if right half is sorted
            else{
                if(target >= nums[m] && target <= nums[r]){
                    l = m+1;
                }
                else{
                    r = m-1;
                }
            }
        }
        return false;
    }
};