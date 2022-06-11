// 1. Sum method: O(n), O(1)

// 2. Binary Search: O(nlogn), O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {  
        int l=0, n = nums.size(), r=n+1, m;
        while(r > l+1){
            m = l + (r-l)/2;
            int cnt=0;
            for(int e: nums){
                if(e < m) cnt++;
            }
            if(cnt < m){
                r = m;
            }
            else{
                l = m;
            }
        }
        return l;
    }
};