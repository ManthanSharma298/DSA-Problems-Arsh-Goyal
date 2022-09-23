

// 1d DP: O(n*logn) for stored in sorted order, O(n+n)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> a;
        map<int, int> mp;
        for(int &e: nums) mp[e]++;
        
        for(auto &p: mp){
            a.push_back(p.first);
        }
        
        int pp=0, p=0, c; 
        for(int i=0; i<a.size(); ++i){
            int e = a[i];
            c = e*mp[e];
            if(i-1 >= 0 && a[i-1]+1 != a[i]){
                c = max(c, e*mp[e] + p);
            }
            else if(i-1 >= 0){
                c = max(p, e*mp[e] + pp);
            }
            pp = p;
            p = c;
        }        
        return c;
    }
};

// Same as House robber
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mp;
        for(int num: nums){
            mp[num]++;
        }
        vector<int> a;
        for(auto e: mp){
            a.push_back(e.first);
        }
        
        int n = a.size();
        vector<int> dp(n+2, 0);
        int mx = 0;
        
        for(int i=2; i<=n+1; ++i){
            if(i > 2 && a[i-3] == a[i-2]-1){
                dp[i] = dp[i-2] + a[i-2]*mp[a[i-2]];
            }    
            else{
                dp[i] = dp[i-1] + a[i-2]*mp[a[i-2]];
            }
            dp[i] = max(dp[i], dp[i-1]);
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};
