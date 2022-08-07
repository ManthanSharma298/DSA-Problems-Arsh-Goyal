

// Time complexity: O(N*2^N) -> to generate all subsets and then copy them into output list
// Space complexity: O(N) -> height of the decision tree
class Solution {
    vector<vector<int>> res;
public:
    void rec(int i, vector<int>& tmp, vector<int>& nums){
        res.push_back(tmp);
        
        for(int j=i; j<nums.size(); ++j){
            if(j > i && nums[j] == nums[j-1]) continue;
            
            tmp.push_back(nums[j]);
            rec(j+1, tmp, nums);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        rec(0, tmp, nums);
        return res;
    }
};