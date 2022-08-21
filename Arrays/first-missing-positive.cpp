

// Array as hashmap: O(3*n), O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // change all -ve numbers to 0
        for(int& num: nums){
            if(num < 0) num = 0;
        }
        int n = nums.size();
        int i = 0;
        // convert array into hashmap
        while(i < n){
            if(nums[i] > 0){
                int id = nums[i]-1;
                if(id > n-1){
                    i++;
                    continue;
                }
                if(nums[id] != -1){
                    swap(nums[i], nums[id]);
                    nums[id] = -1;
                }
                else{
                    i++;
                }
                
            }
            else{
                i++;
            }
        }
        // checking if present in array
        int res = n+1;
        for(int i=1; i<=n; ++i){
            if(nums[i-1] != -1){
                res = i;
                break;
            }
        }
        return res;
    }
};