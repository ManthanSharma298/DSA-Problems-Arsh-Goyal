// 1. brute force: O(n**3) O(1)
// 2. using Hashmap: O(n**2) O(n)

// 3. Sorting + two pointer: O(nlogn) O(logn)

// 3.1 using set: O(nlogn + n**2) O(logn + n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(), target, summ;
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<vector<int>> res;
        
        for(int i=0; i<n; ++i){
            target = -nums[i];
            int l=i+1, r=n-1;
            while(l < r){
                summ = nums[l] + nums[r];
                if(summ == target){
                    st.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(summ < target) l++;
                else r--;
            }
        }
        
        for(auto elm: st){
            res.push_back(elm);
        }
        return res;
    }
};

// 3.2 optimizing by skipping elements: O(nlogn + n**2) O(logn)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(), target, summ;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for(int i=0; i<n-2; ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            target = -nums[i];
            int l=i+1, r=n-1;
            while(l < r){
                summ = nums[l] + nums[r];
                if(summ == target){
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l+1 < r && nums[l] == nums[l+1]) l++;
                    l++;
                    while(r-1 > l && nums[r] == nums[r-1]) r--;
                    r--;
                }
                else if(summ < target) l++;
                else r--;
            }
        }
        return res;
    }
};