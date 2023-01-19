


// O(n*log(log(n)) + 2*log(n) + primes_between(start, end)), O(n)
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> primes(right+1, true);
        vector<int> p;
        primes[0] = primes[1] = false;
        for(int i=1; i<=right; ++i){
            if(primes[i]){
                p.push_back(i);
                for(int j=2; i*j<=right; ++j){
                    primes[i*j] = false;
                }
            }
        }
        auto i1 = lower_bound(p.begin(), p.end(), left);
        auto i2 = upper_bound(p.begin(), p.end(), right);
        int start = i1 - p.begin(), end = i2 - p.begin();
        
        int mn = INT_MAX, lf = -1, rt = -1;
        for(int i=start+1; i<end; ++i){
            if(p[i] - p[i-1] < mn){
                mn = p[i] - p[i-1];
                lf = p[i-1];
                rt = p[i];
            }
        }
        return {lf, rt};
    }
};