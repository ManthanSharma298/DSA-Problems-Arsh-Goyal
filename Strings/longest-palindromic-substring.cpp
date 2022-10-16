

// O(N^2), O(1) -> excluding res
class Solution {
public:
    string longestPalindrome(string s) {
        // odd lengths
        string res = "";
        int mx = 0;
        int n = s.size();
        for(int i=0; i<n; ++i){
            int l = i, r = i;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    l--;
                    r++;
                }
                else break;
            }
            l++;
            r--;
            if(mx < r-l+1){
                mx = r-l+1;
                res = s.substr(l, r-l+1);
            }
        }
        // even lengths
        for(int i=0; i<n-1; ++i){
            int l = i, r = i+1;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    l--;
                    r++;
                }
                else break;
            }
            l++;
            r--;
            if(mx < r-l+1){
                mx = r-l+1;
                res = s.substr(l, r-l+1);
            }
        }
        return res;
    }
};