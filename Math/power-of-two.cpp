
// 1. dividing: O(logn), O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n > 1){
            if(n%2 == 1) return false;
            n /= 2;
        }
        if(n == 1) return true;
        return false;
    }
};

// 2. AND operation: O(1), O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        if((n & (n-1)) == 0) return true;
        return false;
    }
};