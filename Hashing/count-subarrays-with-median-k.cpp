

// Time Complx: O(n), Space Complx: O(n)
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), f = 0, pre = 0, ans = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        // mp[pre - k] for subarray sum equal to k
        for(int i=0; i<n; ++i){
            if(nums[i] == k){
                f = 1;
            }
            if(nums[i] < k){
                pre--;
            }
            else if(nums[i] > k){
                pre++;
            }
            
            // update ans
            // we need subarray sum either 0 or 1
            // only when it contains k that's why we are maintaining boolean flag
            if(f){
                ans += mp[pre] + mp[pre-1];
            }
            // VERY IMPORTANT 
            // consider [3, 5, 2, 4, 1] and k = 3
            //           0, 1, -1, 1, -1
            // if we do not apply this else condition and simply write mp[pre]++
            // for every case then it will consider 5, 2, 4, 1 in mp[0] case
            // for excluding this we will stop updating mp when we reach k
            // which means the values present in mp is the prefix sum less than 
            // index of k 
            // [<----x-k-----><-----k------>]
            // <------------x-------------->
            // when we are searching x-k in map it means that we take the next subarray
            // but in case of median we need to take k always, we can't skip it
            // then fill map till elements whose index is less than index of k
            else{
                mp[pre]++;
            }
        }
        return ans;
    }
};