

// O(N*2^N), O(N+N) by symmetry of other backtracking solutions
class Solution {
    vector<vector<string>> res;
public:
    bool is(string s){
        int l = 0, r = s.size()-1;
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    void rec(int i, vector<string>& tmp, string& s){
        if(i == s.size()){
            res.push_back(tmp);
        }
        for(int j=i; j<s.size(); ++j){
            string ts = s.substr(i, j-i+1);
            if(is(ts)){
                tmp.push_back(ts);
                rec(j+1, tmp, s);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        rec(0, tmp, s);
        return res;
    }
};