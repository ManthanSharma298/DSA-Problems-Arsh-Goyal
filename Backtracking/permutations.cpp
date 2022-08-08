


// 1. Using vis array: O(n!*n), O(n+n+n) -> rec+tmp+vis
class Solution {
    vector<vector<int>> res;
public:
    void rec(int i, vector<int>& vis, vector<int>& tmp, vector<int>& nums){
        if(i == nums.size()){
            res.push_back(tmp);
        }
        for(int j=0; j<nums.size(); ++j){
            if(vis[j] == 0){
            	vis[j] = 1;
            	tmp.push_back(nums[j]);
            	rec(i+1, vis, tmp, nums);
            	tmp.pop_back();
            	vis[j] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vis(nums.size(), 0);
        vector<int> tmp;
        rec(0, vis, tmp, nums);
        return res;
    }
};


// 2. Swapping: O(n!*n), O(n) -> rec
class Solution {
    vector<vector<int>> res;
public:
    void rec(int i, vector<int>& nums){
        if(i == nums.size()){
            res.push_back(nums);
        }
        for(int j=i; j<nums.size(); ++j){
            swap(nums[i], nums[j]);
            rec(i+1, nums);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        rec(0, nums);
        return res;
    }
};
