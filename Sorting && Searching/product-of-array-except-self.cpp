
// Suffix product: O(n), O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);
        int pro = 1;
        
        res[n-1] = nums[n-1];
        for(int i=n-2; i>=0; --i){
            res[i] = nums[i]*res[i+1];
        }
        
        for(int i=0; i<n-1; ++i){
            res[i] = res[i+1]*pro;
            pro *= nums[i];
        }
        res[n-1] = pro;
        
        return res;
    } 
};