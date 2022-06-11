
// buy when price is low: O(n), O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pf = 0, buy = prices[0], prev = prices[0];
        int n = prices.size();
        for(int i=1; i<n; ++i){
            if(prices[i] < prices[i-1]){
                pf += (prices[i-1] - buy);
                buy = prices[i];
            }
        }
        pf += prices[n-1] - buy;
        return pf;
    }
};