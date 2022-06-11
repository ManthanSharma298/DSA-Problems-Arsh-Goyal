
// Basic addition using carry: O(n), O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, curr,aa=a.size(), bb=b.size();
        string res;
        int i=aa-1, j=bb-1;
        
        while(i>=0 || j>=0){
            curr = 0;
            if(i >= 0){
                curr += (a[i]-'0');
            }
            if(j >= 0){
                curr += (b[j]-'0');
            }
            curr += carry;
            if(curr == 0){
                res = '0' + res;
                carry = 0;
            }
            else if(curr == 1){
                res = '1' + res;
                carry = 0;
            }
            else if(curr == 2){
                res = '0' + res;
                carry = 1;
            }
            else{
                res = '1' + res;
                carry = 1;
            }
            i--;
            j--;
        }
        
        if(carry > 0){
            char c = carry + '0';
            res = c + res;
        }
        
        return res;
    }
};