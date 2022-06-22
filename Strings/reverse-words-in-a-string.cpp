

// in-place algorithm: O(n+n), O(1)
class Solution {
public:
    void rev(string &s, int l, int r){
        char tmp;
        while(l < r){
            tmp = s[l];
            s[l++] = s[r];
            s[r--] = tmp;
        }
    }
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        s += ' ';
        int i=0, j=0, l, r, n = s.size();
        while(true){
            // skipping leading spaces
            while(i < n && s[i] == ' ') i++;
            if(i == n) break;
            
            // shifting word
            l = j;
            while(i < n && s[i] != ' '){
                s[j++] = s[i++];
            }
            // reversing curr word
            rev(s, l, j-1);
            
            if(j < n){
                s[j++] = ' ';
            }
        }
        s.resize(j-1);
        return s;
    }
};