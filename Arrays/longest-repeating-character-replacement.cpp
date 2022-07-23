

// Sliding window: O(n*26), O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, n=s.size();
        int cnt[26] = {0};
        int len = 0, mxCnt;
        
        while(l <= r && r <= n){
            mxCnt = 0;
            for(int i=0; i<26; ++i)  mxCnt = max(mxCnt, cnt[i]);
            int req = r-l-mxCnt;
            if(req > k){
                cnt[s[l++]-'A']--;
            }
            else{
                len = max(len, r-l);
            }
            if(r < n) cnt[s[r]-'A']++;
            r++;
        }
        return len;
    }
};