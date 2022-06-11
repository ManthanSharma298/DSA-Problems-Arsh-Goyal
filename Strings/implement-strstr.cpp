// 1. Brute force: O(n*m), O(1)
// 2. KMP: I am not going to learn now

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size(), h = haystack.size();
        if(n == 0) return 0;
        
        int l=0, r=0;
        while(l < h && r < n){

            if(haystack[l] == needle[r]){
                l++;
                r++;
            }
            else{
                l = l-r+1;
                r = 0;
            }
        }
        if(r == n) return l-r;
        return -1;
    }       
};