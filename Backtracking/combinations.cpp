

// O(k*n^k), O(n)
class Solution {
    vector<vector<int>> res;
public:
    void rec(int i, int n, vector<int>& tmp, int k){
        if(k == 0){
            res.push_back(tmp);
            return;
        }
        for(int j=i; j<=n-k+1; ++j){
            tmp.push_back(j);
            rec(j+1, n, tmp, k-1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        rec(1, n, tmp, k);
        return res;
    }
};