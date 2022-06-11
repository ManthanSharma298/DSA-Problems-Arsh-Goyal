// 1. brute force: O(n**2) O(1)

// 2. suffix-sum: O(n) O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), suff=0, mx=0;
        for(int i=n-1; i>=0; --i){
            mx = max(mx, suff - prices[i]);
            suff = max(suff, prices[i]);
        }
        return mx;
    }
};

// 3. prefix-sum or DP: O(n) O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), pre=nums[0], mx=0;
        for(int i=1; i<n; ++i){
            mx = max(mx, nums[i] - pre);
            pre = min(pre, nums[i]);
        }
        return mx;
    }
};