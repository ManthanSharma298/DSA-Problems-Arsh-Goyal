

// 1. pointers + Hashing: O(N), O(26) ~ O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        unordered_map<char, int> mp;
        for(int i=0; i<n; ++i){
            mp[s[i]] = i;
        }
        int str = 0, end;
        while(str < n){
            end = mp[s[str]];
            for(int i = str; i <= end; ++i){
                end = max(end, mp[s[i]]);
            }
            ans.push_back(end - str + 1);
            str = end + 1;
        }
        return ans;
    }
};

// 2. Same approach, diff implementation
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        vector<int> mp(26, 0);
        for(int i=0; i<n; ++i){
            mp[s[i] - 'a'] = i;
        }
        int prev = 0, end = 0;
        for(int i=0; i<n; ++i){
            end = max(end, mp[s[i] - 'a']);
            // do partition
            if(i == end){
                ans.push_back(end - prev + 1);
                prev = end + 1;
            }
        }
        return ans;
    }
};