
// extension of 3sum: O(nlogn + n**3) ~ O(n**3) O(logn)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(), t1, t2, summ;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for(int k=0; k<n-3; ++k){
            if(k > 0 && nums[k] == nums[k-1]) continue;
            t1 = target - nums[k];
            
            for(int i=k+1; i<n-2; ++i){
                if(i > k+1 && nums[i] == nums[i-1]) continue;
                t2 = t1 - nums[i];
                int l=i+1, r=n-1;
                while(l < r){
                    summ = nums[l] + nums[r];
                    if(summ == t2){
                        res.push_back({nums[k], nums[i], nums[l], nums[r]});
                        
                        while(l+1 < r && nums[l] == nums[l+1]) l++;
                        l++;
                        while(r-1 > l && nums[r] == nums[r-1]) r--;
                        r--;
                    }
                    else if(summ < t2) l++;
                    else r--;
                }
            }
        }
        return res;
    }
};