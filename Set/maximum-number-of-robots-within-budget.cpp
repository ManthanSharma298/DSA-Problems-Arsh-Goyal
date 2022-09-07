

// sliding window + multiset: O(n*logn), O(n)
class Solution {
public:
    int maximumRobots(vector<int>& time, vector<int>& cost, long long budget) {
        long long n = time.size(), l = 0, r = 0;
        long long curr = 0;
        long long mx = 0;
        long long cc = 0, res = 0;
        multiset<int> ms;
        while(r < n){
            ms.insert(time[r]);
            // USE rbegin() not r.end()
            mx = *(ms.rbegin());
            cc += cost[r];
            curr = mx + (r-l+1)*cc;
            
            if(curr > budget){
                cc -= cost[l];
                auto it = ms.find(time[l]);
                ms.erase(it);
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};