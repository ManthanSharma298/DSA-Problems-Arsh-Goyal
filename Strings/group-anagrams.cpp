

// 1. hashmap + sort: O(n*mlogm), O(n*(m + logm))
// where n: strs.size(), m: strs[i].size()
class Solution {
public:               
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto &s: strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(s);
        }
        
        vector<vector<string>> res;
        for(auto e: mp){
            res.push_back(e.second);
        }
        return res;
    }
};

// hashmap + counting sort: O(n*m*26), O(n*(m + 26))
class Solution {
public:        
    string cntSort(string s){
        int cnt[26] = {0};
        for(char ch: s){
            cnt[ch - 'a']++;
        }
        
        string res = "";
        for(int i=0; i<26; ++i){
            for(int j=0; j<cnt[i]; ++j){
                res += i + 'a';
            }
        }
        
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto &s: strs){
            string tmp = cntSort(s);
            mp[tmp].push_back(s);
        }
        
        vector<vector<string>> res;
        for(auto e: mp){
            res.push_back(e.second);
        }
        return res;
    }
};