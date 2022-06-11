// 1. counting number of zero, one and then fill them O(2*n) O(1)

// 2. swaping
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(), l=0, r=n-1,i=0;
        while(i >= l && i <= r){
            if(nums[i] == 0){
                nums[i] = nums[l];
                nums[l] = 0;
                l++;
                i++;
            }
            else if(nums[i] == 2){
                nums[i] = nums[r];
                nums[r] = 2;
                r--;
            }
            else{
                i++;
            }
        }
    }
};