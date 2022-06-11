
// prefix sum + hashmap: O(n) O(n)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int pre = 0;
        mp[0]++;
        for(int i=0; i<n; ++i){
            pre = (pre + nums[i])%k;
            if(pre < 0) pre += k;
            mp[pre]++;
        }
        int res = 0;
        for(auto e: mp){
            res += (e.second*(e.second-1))/2;   // C(n,2)
        }
        return res;
    }
};