
// 1. prefix-array: o(n) O(n) 
class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        vector<int> pre(n);
        pre[0] = a[0];
        for(int i=1; i<n; ++i){
            pre[i] = pre[i-1] + a[i];
        }
        int sm = 0, res = 0, l=n-1;
        for(int j=k-1; j>=-1 && j<n; --j){
            if(j < 0){
                res = max(res, sm);
            }
            else{
                res = max(res, pre[j] + sm);
                sm += a[l--];
            }
        }
        
        return res;
    }
};

// 2. sliding window: O(n) O(1)
class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size(), l=n-1, f=k-1, curr=0, mx=0;
        for(int i=0 ;i<k; ++i) curr += a[i];
        mx = max(mx, curr);
        
        while(f >= 0){
            curr -= a[f--];
            curr += a[l--];
            mx = max(mx, curr);
        }
        return mx;
    }
};
