

// Using HashMap: O(n!*n), O(n+n)
class Solution {
    unordered_map<int,int> f;
    vector<vector<int>> res;
public:
    
    void rec(vector<int>& tmp, vector<int>& nums){
        if(tmp.size() == nums.size()){
            res.push_back(tmp);
        }
        for(auto e: f){
            if(e.second > 0){
                tmp.push_back(e.first);
                f[e.first]--;
                rec(tmp, nums);
                tmp.pop_back();
                f[e.first]++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int e: nums) f[e]++;
        vector<int> tmp;
        rec(tmp, nums);
        return res;
    }
};