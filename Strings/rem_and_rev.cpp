

// Two pointers: O(n), O(n)
class Solution {
  public:
    string removeReverse(string S) {
        int n = S.size(), f = 0, l = 0, r = n-1;
        unordered_map<char, int> cnt;
        for(char c: S) cnt[c]++;
        
        while(l <= r){
            // left to right
            if(f == 0){
                if(cnt[S[l]] > 1){
                    cnt[S[l]]--;
                    S[l] = '#';
                    f = 1;
                }
                l++;
            }
            // right to left
            else{
                if(cnt[S[r]] > 1){
                    cnt[S[r]]--;
                    S[r] = '#';
                    f = 0;
                }
                r--;
            }
        }
        // cout<<S<<"\n";
        string res;
        if(f == 0){
            for(int i=0; i<n; ++i){
                if(S[i] != '#') res += S[i];
            }
        }
        else{
            for(int i=n-1; i>=0; --i){
                if(S[i] != '#') res += S[i];
            }
        }
        return res;
    }
};