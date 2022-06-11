

// 1. linear: O(n), O(1) 

// 2. Binary search: O(logn), O(1)

// In order to apply binary search we need to convert 2 conditions to 1 condition
// for e.g. in this case arr[i] > arr[i+1] && arr[i] > arr[i-1] can be converted to return i when arr[i] > arr[i+1]
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l=-1, r=n-1, m;
        
        while(l+1 < r){
            m = l + (r-l)/2;
            if(nums[m] > nums[m+1]) r = m;
            else l = m;
        }
        return r;
    }
};