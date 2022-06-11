
// maintaining overflow: O(logn), O(1)
// as we cannot use long long or 64 bit integers
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        
        while(x){
            int rem = x%10;
            // overflow conditions
            if(res > INT_MAX/10 || (res == INT_MAX/10 && rem > 7)) return 0;
            if(res < INT_MIN/10 || (res == INT_MIN/10 && rem < -8)) return 0;
            
            res = res*10 + rem;
            x /= 10;
        }
        
        return res;
    }
};

// +2147483647 -> INT_MAX
// -2147483648 -> INT_MIN