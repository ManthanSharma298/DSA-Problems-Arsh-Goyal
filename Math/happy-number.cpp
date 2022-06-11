
// O(100) or O(logn), O(1)
class Solution {
public:
    int conv(int x){
        int res = 0;
        while(x > 0){
            int dig = x%10;
            x /= 10;
            res += dig*dig;
        }
        return res;
    }
    
    bool isHappy(int n) {
        int stp = 100;
        while(stp--){
            n = conv(n);
            if(n == 1) return true;
        }
        return false;
    }
};