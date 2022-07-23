

// 1. counting number of zero, one and then fill them O(2*n) O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zr=0, on=0;
        for(int num: nums){
            if(num == 1) on++;
            else if(num == 0) zr++;
        }
        for(int i=0; i<nums.size(); ++i){
            if(zr > 0) {nums[i] = 0; zr--;}
            else if(on > 0) {nums[i] = 1; on--;}
            else nums[i] = 2;
        }
    }
};

// 2. two-pointer: O(n), O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(), l=0, i=0, r=n-1;
        while(i <= r){
            if(nums[i] == 0){
                swap(nums[i++], nums[l++]);
            }
            else if(nums[i] == 2){
                swap(nums[i], nums[r--]);
            }
            else{
                i++;
            }
        }
    }
};