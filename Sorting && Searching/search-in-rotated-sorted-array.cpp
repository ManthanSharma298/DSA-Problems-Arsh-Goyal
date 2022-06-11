
// Linear Search: O(n), O(1)

// Binary Search: O(logn), O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1, m;
        while(l+1 < r){
            m = l + (r-l)/2;
            if(nums[l] < nums[m]){
                if(nums[l] <= target && target <= nums[m]){
                    r = m;  // holds ans
                }
                else{
                    l = m;
                }
            }
            else{
                if(target < nums[l] && target > nums[m]) l = m;
                else r = m; // holds ans
            }
        }
        if(nums[l] == target) return l;
        if(nums[r] == target) return r;
        return -1;
    }
};

// Another template of BS: O(logn), O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1, m;
        while(l < r){
            m = l + (r-l)/2;
            // nums[l] < nums[m] doesn't work here e.g. [1,3], target=3
            if(nums[l] <= nums[m]){
                if(nums[l] <= target && target <= nums[m]){
                    r = m;  
                }
                else{
                    l = m+1;
                }
            }
            else{
                if(target < nums[l] && target > nums[m]) l = m+1;
                else r = m; 
            }
        }
        return nums[l] == target ? l : -1;
    }
};