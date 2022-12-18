

// Great application of LCA and complete binary tree
// q: number of queries, N: number of nodes in tree
// O(q*log(N)), O(log(N))
class Solution {
public:
    int lca(int a, int b){
        if(a == b) return 0;
        if(a < b) return lca(b, a);
        return lca(b, a/2) + 1;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto q: queries){
            int curr = lca(q[0], q[1]) + 1;
            ans.push_back(curr);
        }
        return ans;
    }
};