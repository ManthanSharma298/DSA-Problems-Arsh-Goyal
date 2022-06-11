
// swapping: O(n) O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), l=0, r=0, tmp;
        while(l <= r && r < n){
            if(nums[r] == 0){
                r++;
            }
            else{
                tmp = nums[l];
                nums[l] = nums[r];
                nums[r] = tmp;
                l++;
                r++;
            }
        }
    }
};
