// 1. Brute force: O(n**2) O(1)

// 2. Two pointer approach: O(n) O(1)
class Solution {
public:
    int maxArea(vector<int>& h) {
        // max{(j-i)*min(h[i], h[j])}
        int n=h.size(), l=0, r=n-1, res=0;
        while(l < r){
            if(h[l] < h[r]){
                res = max(res, (r-l)*h[l]);
                l++;
            }
            else{
                res = max(res, (r-l)*h[r]);
                r--;
            }
        }
        return res;
    }
};