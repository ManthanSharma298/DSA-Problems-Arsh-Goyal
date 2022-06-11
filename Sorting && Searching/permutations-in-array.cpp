
// Sorting: O(nlogn + n), O(logn)
class Solution {
  public:
    bool isPossible(long long a[], long long b[], long long n, long long k) {
        sort(a, a+n);
        sort(b, b+n);
        reverse(b, b+n);
        
        for(long long i=0; i<n; ++i){
            if(a[i] + b[i] < k) return false;
        }
        return true;
    }
};