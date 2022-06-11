// 1. Brute force: O(n*n), O(1)

// 2. Skip one character: O(n), O(1)
class Solution {
public:
    bool is(string s, int l, int r){
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
        
    }
    bool validPalindrome(string s) {
        int n = s.size(), l=0, r=n-1;
        while(l < r){
            if(s[l] != s[r]){
                return is(s, l+1, r) || is(s, l, r-1);
            }
            else{
                l++;
                r--;
            }
        }
        return true;
    }
};