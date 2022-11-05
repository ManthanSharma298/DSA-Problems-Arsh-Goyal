


// Hashing: O(n + n) ~ O(n), O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int num: nums){
            st.insert(num);
        }
        
        int len = 0, curr = 0;
        for(int num: nums){
            if(st.find(num+1) != st.end()) continue;
            
            curr = 0;
            while(st.find(num) != st.end()){
                num--;
                curr++;
            }
            
            len = max(len, curr);
        }
        return len;
    }
};