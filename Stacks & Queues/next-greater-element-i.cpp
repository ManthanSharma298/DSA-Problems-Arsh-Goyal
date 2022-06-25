
// 1. Brute force: O(n**2), O(1)

// 2. Monotonic stack: O(n+m), O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int h = 0;
        vector<int> res(nums1.size(), -1);
        unordered_map<int, int> mp;
        for(int i=0; i<nums1.size(); ++i){
            mp[nums1[i]] = i;
        }
        stack<int> ms;
        int i=0;
        while(i < nums2.size()){
            while(!ms.empty() && nums2[i] > ms.top()){
                if(mp.count(ms.top())){
                    res[mp[ms.top()]] = nums2[i];
                }
                ms.pop();
            }
            ms.push(nums2[i++]);
        }
        return res;
    }
};