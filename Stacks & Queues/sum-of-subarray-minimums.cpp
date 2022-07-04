

// 1. Brute force: O(n*n), O(1)

// 2. Monotonic stack: O(n), O(n)
class Solution {
    int mod = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int,int>> s;
            
        int res = 0, n = arr.size();
        int l, m, r;
        for(int i=0; i<n; ++i){  
            while(!s.empty() && arr[s.top().first] > arr[i]){
                auto tp = s.top();
                s.pop();
                l = tp.second, r = i-1, m = tp.first;
                // for top element
                long long pro = ((m-l+1)*(r-m+1))%mod;
                pro = (pro * arr[tp.first])%mod;
                res = (res + pro)%mod;
            }
            if(s.empty()) s.push({i, 0});
            else s.push({i, s.top().first+1});
        }
        r = n-1;
        while(!s.empty()){
            auto tp = s.top();
            s.pop();
            l = tp.second, m = tp.first;
            long long pro = ((m-l+1)*(r-m+1))%mod;
            pro = (pro * arr[tp.first])%mod;
            res = (res + pro)%mod;
        }
        return res;
    }
};