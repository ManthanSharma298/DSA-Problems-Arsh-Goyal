
// ASCII Value: O(logn base 26), O(1)
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0){
            int dig = (n-1)%26;
            n = (n-1)/26;
            char ch = 'A' + dig;
            res =  ch + res;
        }
        return res;
    }
};