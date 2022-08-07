

// Time complexity: O(N*2^N) -> to generate all subsets and then copy them into output list
// Space complexity: O(N) -> height of the decision tree
class Solution {
    vector<vector<int>> res;
public:
    void rec(int i, vector<int>& tmp, vector<int>& nums){
        res.push_back(tmp);
        
        for(int j=i; j<nums.size(); ++j){
            tmp.push_back(nums[j]);
            rec(j+1, tmp, nums);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        rec(0, tmp, nums);
        return res;
    }
};