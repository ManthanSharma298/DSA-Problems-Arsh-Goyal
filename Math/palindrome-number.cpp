
// 1. Using external string or vector: O(logn), O(logn)
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        vector<int> t;
        while(x > 0){
            int dig = x%10;
            x /= 10;
            t.push_back(dig);
        }
        int l=0, r=t.size()-1;
        while(l < r){
            if(t[l++] != t[r--]) return false;
        }
        return true;
    }
};

// 2. Compare number itself: O(logn), O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        long long unit = 1;
        while(x/unit != 0){
            unit *= 10;
        }
        unit /= 10;
        
        while(unit){
            int right = x%10, left = x/unit;
            if(right != left) return false;
            x %= unit;
            x /= 10;
            unit /= 100;
        }
        return true;
    }
};