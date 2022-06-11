// 1. Hashing O(n) O(n)

// 2. Negative Indexing O(n) O(1) but modifies the array
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size(), num;
        vector<int> res;
        for(int i=0; i<n; ++i){
            num = abs(nums[i]);
            if(nums[num-1] < 0){
                res.push_back(num);
            }
            else{
                nums[num-1] *= -1;
            }
        }
        return res;
    }
};