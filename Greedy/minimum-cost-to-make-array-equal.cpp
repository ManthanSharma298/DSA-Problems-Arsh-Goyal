

// sorting: O(N + N*logN + N + N) ~ O(N*logN), O(2*N)
#define ll long long 
class Solution {
public:
    static bool cmp(pair<ll,ll>& a, pair<ll,ll>& b){
        return a.first < b.first;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll res = 0, tot = 0;
        int n = nums.size(), val;
        
        vector<pair<ll,ll>> a;
        for(int i=0; i<n; ++i){
            a.push_back({nums[i], cost[i]});
            tot += cost[i];
        }
        sort(a.begin(), a.end(), cmp);
        
        tot /= 2;
        tot++;  // to convert into 1 based index
        ll curr = 0;
        for(int i=0; i<n; ++i){
            curr += a[i].second;
            if(curr >= tot){
                val = a[i].first;
                break;
            }
        }
        for(int i=0; i<n; ++i){
            res += (abs(a[i].first - val)) * a[i].second;
        }
        return res;
    }
};