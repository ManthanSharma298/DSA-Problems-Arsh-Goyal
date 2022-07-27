

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