

// Sliding window: O(n+n), O(n)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char&c: t){
            mp[c]++;
        }
        int l=0, r=0, sz = INT_MAX, ll, rr, have = 0, need = mp.size();
        while(l <= r && r < s.size()){
            // 1. addtion condition
            auto it = mp.find(s[r]);
            if(it != mp.end()){
                mp[s[r]]--;
                if(mp[s[r]] == 0) have++;
            }
            // 2. removing condition by while loop
            while(l <= r && have >= need){
                // have >= need also a valid option
                if(r-l+1 < sz){
                    sz = r-l+1;
                    ll = l;
                    rr = r;
                }
                // remove left one
                auto it = mp.find(s[l]);
                if(it != mp.end()){
                    mp[s[l]]++;
                    // decrement have when all it's frequency is removed i.e. mp[element] > 0 
                    if(mp[s[l]] > 0) have--;
                }
                l++;
            }   
            r++;
        }
        string ans = "";
        if(sz != INT_MAX){
            ans = s.substr(ll, rr-ll+1);
        }
        return ans;
    }
};