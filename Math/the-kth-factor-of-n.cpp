
// 1. Brute force: O(n), O(1)
class Solution {
public:
    int kthFactor(int n, int k) {
        for(int i=1; i<=n; ++i){
            if(n%i == 0){
                if(k == 1) return i;
                k--;
            }
        }
        return -1;
    }
};

// 2. O(2*sqrt(n)), O(1)
class Solution {
public:
    int kthFactor(int n, int k) {
        int i;
        for(i=1; i*i<n; ++i){
            if(n%i == 0){
                if(k == 1) return i;
                k--;
            }
        }
        for(; i>=1; --i){
            if(i*i<=n && n%i == 0){
                if(k == 1) return n/i;
                k--;
            }
        }
        return -1;
    }
};

 