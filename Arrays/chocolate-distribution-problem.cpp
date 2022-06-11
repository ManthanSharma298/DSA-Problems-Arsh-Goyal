
// sliding window: O(nlogn + n) O(logn)
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        long long l=0, r=m-1, res=1e10;
        sort(a.begin(), a.end());
        while(r < n){
            res = min(res, a[r++] - a[l++]);
        }
        return res; 
    }   
};