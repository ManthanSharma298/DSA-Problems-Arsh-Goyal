

// pointers + Hashing: O(N), O(26) ~ O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char, int> mp;
        int n = s.size();
        for(int i=n-1; i>=0; --i){
            if(mp.find(s[i]) == mp.end()) mp[s[i]] = i;
        }
        int l = 0, r = 0, cr;
        for(int i=0; i<n; ++i){
            cr = mp[s[i]];
            if(r < i){
                ans.push_back(r-l+1);
                l = i;
                r = mp[s[i]];
            }
            else if(r < cr) r = cr;
        }
        ans.push_back(r-l+1);

        return ans;
    }
};