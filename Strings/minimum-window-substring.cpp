

// Sliding window: O(n+n), O(n)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char &ch: t){
            mp[ch]--;
        }
        
        int have = 0, need = mp.size();
        int l=0, r=0, ll=0, rr=0, min=INT_MAX;
        
        while(l <= r && r < s.size()){
            if(mp.count(s[r])){
                mp[s[r]]++;
                if(mp[s[r]] == 0){
                    have++;
                }
            }
            while(have >= need && l <= r){
                if(r-l+1 < min){
                    min = r-l+1;
                    ll = l;
                    rr = r;
                }
                if(mp.count(s[l])){
                    mp[s[l]]--;
                    if(mp[s[l]] < 0){
                        have--;
                    }
                }
                l++;
            }
            r++;
        }
        
        string res = "";
        if(min != INT_MAX){
            for(int i=ll; i<=rr; ++i){
                res += s[i];
            }
        }
        return res;
    }
};