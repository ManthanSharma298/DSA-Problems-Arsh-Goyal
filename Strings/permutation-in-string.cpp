

// 1. Using Hashmap: O(26*M): O(26*2)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size(), l = 0, r = 0;
        unordered_map<char, int> mp1, mp2;
        for(char c: s1){
            mp1[c]++;
        }
        while(r < m){
            mp2[s2[r]]++;
            if(r-l+1 > n){
                mp2[s2[l++]]--;
            }
            if(r-l+1 == n){
                int f = 1;
                for(auto e: mp1){
                    if(mp2[e.first] != e.second){
                        f = 0;
                        break;
                    }
                }
                if(f) return true;
            }
            r++;
        }
        return false;
    }
};


// 2. Optimisation: O(M), O(26*2)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size(), l = 0, cnt = 0, curr;
        if(n > m) return false;
        vector<int> s(26, 0), t(26, 0);
        for(int i=0; i<n; ++i){
            s[s1[i] - 'a']++;
            t[s2[i] - 'a']++;    
        }
        for(int i=0; i<26; ++i){
            cnt += (s[i] == t[i]);
        }
        for(int r = n; r < m; ++r){
            if(cnt == 26) return true;
            curr = s2[r] - 'a';
            // adding
            t[curr]++;
            if(s[curr] == t[curr]) cnt++;
            else if(s[curr] + 1 == t[curr]) cnt--;
            
            // removing
            curr = s2[l++] - 'a';
            t[curr]--;
            if(s[curr] == t[curr] + 1) cnt--;
            else if(s[curr] == t[curr]) cnt++;
        }
        return cnt == 26;
    }
};
