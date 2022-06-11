
// IMPORTANT: AS NUMBERS CAN BE NEGATIVE SO CAN'T USE SLIDING WINDOW

// 1. Brute force: O(n**2) O(1)

// 2. Hashmap: O(n) O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), cnt=0, pre=0;
        unordered_map<int,int> pf;  // prefix_sum, count
        pf[0] = 1;
        for(int i=0; i<n; ++i){
            pre += nums[i];
            auto it = pf.find(pre-k);
            if(it != pf.end()) cnt += pf[pre-k];
            
            pf[pre]++;
        }
        return cnt;
    }
};