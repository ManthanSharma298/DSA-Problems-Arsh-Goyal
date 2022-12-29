

// O(N*logN), O(1)
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int l = 0, r = 1e9, ans, diff, n = price.size();
        while(l <= r){
            diff = l + (r - l)/2;
            int cnt = 1, curr, prev = 0;
            for(int i=1; i<n; ++i){
                curr = price[i] - price[prev];
                if(curr >= diff){
                    cnt++;
                    prev = i;
                }
            }   
            if(cnt >= k){
                ans = diff;
                l = diff + 1;
            }
            else{
                r = diff - 1;
            }
        }
        return ans;
    }
};