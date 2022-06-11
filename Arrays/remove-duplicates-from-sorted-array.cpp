
// modifying the array: O(n) O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), f=0, l=1;
        if(n == 1) return 1;
        while(l < n && f < l){
            if(nums[f] == nums[l]){
                l++;
            }
            else{
                nums[f+1] = nums[l];
                l++;
                f++;
            }
        }
        return f+1; // because of zero indexing
    }
    // {1,1,1,2,2,2,3}
};
