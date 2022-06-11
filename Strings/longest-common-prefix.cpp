
// Brute force: O(n*m), O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int sz = strs[0].size(), n = strs.size();
        if(n == 1) return strs[0];
        
        for(int i=0; i<sz; ++i){
            int fg = 0;
            for(int j=1; j<n; ++j){
                if(i < strs[j].size() && strs[j][i] == strs[0][i]){
                    if(j == n-1) res += strs[0][i];
                    continue;
                }
                else if(i >= strs[j].size() || strs[j][i] != strs[0][i]){
                    fg = 1;
                    break;
                }
            }
            if(fg) break;
        }      
        return res;
    }
};