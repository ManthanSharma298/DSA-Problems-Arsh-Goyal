

// Compare rev/10 with INT_MAX/10
// O(log(x,10)), O(1)
class Solution {
public:
    int reverse(int x) {
        int ans = 0, dig;
        while(x){
            dig = x % 10;
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && dig > 7)) return 0;
            if(ans < INT_MIN/10 || (ans == INT_MIN/10 && dig < -8)) return 0;
                
            ans = ans * 10 + dig;
            x /= 10;
        }
        return ans;
    }
};