

// monotonic stack of size k: O(n), O(k)
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // since we have to return a vector we can use vector as stack
        // pop_back, push_back, vector.back() has time complexity O(1)
        vector<int> st;
        int n = nums.size();
        for(int i=0; i<n; ++i){
            while(st.size() > 0 && nums[i] < st.back() && st.size() + n-i > k){
                st.pop_back();
            }
            if(st.size() < k) st.push_back(nums[i]);
        }
        return st;
    }
};