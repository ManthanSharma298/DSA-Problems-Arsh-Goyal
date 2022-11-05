
// Linear Search: O(n), O(1)

// Binary Search: O(logn), O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1, m;
        while(l+1 < r){
            m = l + (r-l)/2;
            // if left half is sorted
            if(nums[l] < nums[m]){
                if(target >= nums[l] && target <= nums[m]){
                    r = m;
                }
                else{
                    l = m;
                }
            }
            // if right half is sorted
            else{
                if(target >= nums[m] && target <= nums[r]){
                    l = m;
                }
                else{
                    r = m;
                }
            }
        }
        if(target == nums[l]) return l;
        if(target == nums[r]) return r;
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


// Another template with l <= r
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1, m;
        while(l <= r){
            m = l + (r-l)/2;
            if(nums[m] == target) return m;
            // if left half is sorted
            if(nums[l] <= nums[m]){
                if(target >= nums[l] && target <= nums[m]){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
            // if right half is sorted
            else{
                if(target >= nums[m] && target <= nums[r]){
                    l = m+1;
                }
                else{
                    r = m-1;
                }
            }
        }
        return -1;
    }
};                                                          