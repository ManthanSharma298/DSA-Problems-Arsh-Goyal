

// Binary search: O(log(mx_num)*n*n), O(1) -> except m 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int n = m.size(), l = m[0][0]-1, r = m[n-1][n-1];
        
        while(l+1 < r){
            int num = l + (r-l)/2;
            int cnt = 0;
            for(auto v: m){
                for(auto e: v){
                    if(e <= num) cnt++;
                }
            }
            // cnt = k is the ans
            if(cnt >= k) r = num; // holds ans
            else l = num; 
        }
        return r;
    }
};

// we can optimize for cnt by using upper_bound or binary search 