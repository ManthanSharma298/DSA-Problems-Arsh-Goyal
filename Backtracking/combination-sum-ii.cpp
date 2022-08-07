

// Backtraking: O(2^N*k + N*logN), O(N)->used by stack
// In backtracking time complex is always the total number of combinations possible
// multiplied by k as res.push is O(k) operation 
class Solution {
    vector<vector<int>> res;
public:
    void rec(int i, vector<int>& tmp, vector<int>& a, int target){
        if(target == 0){
            res.push_back(tmp);
            return;
        }
        if(target < 0) return;
        int n = a.size();
        for(int j=i; j<n; ++j){
            if(j > i && a[j] == a[j-1]) continue;
            tmp.push_back(a[j]);
            rec(j+1, tmp, a, target-a[j]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        rec(0, tmp, candidates, target);
        
        return res;
    }
};