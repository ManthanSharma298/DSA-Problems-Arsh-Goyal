

// 1. Using set: O(n + k*k), O(k + k)
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for(char ch: s){
            mp[ch]++;
        }
        int cnt = 0;
        unordered_set<int> st;
        for(auto it = mp.begin(); it != mp.end(); ++it){
            int curr = it->second;
            while(curr > 0 && st.find(curr) != st.end()){
                curr--;
            }
            if(curr > 0) st.insert(curr);
            cnt += it->second - curr;
        }
    
        return cnt;
    }
};

// k: 26
// 2. Using sorting: O(n + k*logk + k), O(k + k)
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for(char ch: s){
            mp[ch]++;
        }
        int cnt = 0;
        vector<int> f;
        for(auto it = mp.begin(); it != mp.end(); ++it){
        	f.push_back(it->second);
        }
        sort(f.begin(), f.end(), greater<int>());

        for(int i=1; i<f.size(); ++i){
        	if(f[i] >= f[i-1]){
        		int tmp = f[i];
        		f[i] = max(0, f[i-1]-1);
        		cnt += tmp - f[i];
        	}
        }
    
        return cnt;
    }
};
