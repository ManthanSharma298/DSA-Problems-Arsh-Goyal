// 1. Brute force: O(n**2) O(1)

// 2. using Hashmap or storage: O(n) O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> id;
        
        for(int  i=0; i<n; ++i){
            if(id.count(target - nums[i])) return {id[target-nums[i]], i};
            else id[nums[i]] = i;
        }
        return {};
    }
};