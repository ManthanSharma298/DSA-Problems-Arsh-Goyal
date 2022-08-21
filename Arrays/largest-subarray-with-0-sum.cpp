

// Using map: O(n+n), O(n)
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        map<int, vector<int>> mp;
        mp[0].push_back(0);
        
        int pre = 0;
        for(int i=0; i<n; ++i){
            pre += A[i];
            mp[pre].push_back(i+1);
        }
        int res = 0, curr;
        for(auto e: mp){
            curr = e.second.back() - e.second[0];
            res = max(res, curr);
        }
        return res;
    }
};