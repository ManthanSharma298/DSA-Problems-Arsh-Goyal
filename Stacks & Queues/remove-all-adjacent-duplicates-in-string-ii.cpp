

// 1. Brute force: O(n*k), O(1)

// 2. Using stack: O(n+k), O(n+n)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int n = s.size(), i = n-1;
        while(i >= 0){
            if(!st.empty() && st.top().first == s[i]){
                st.push({s[i], st.top().second+1});
            }
            else{
                st.push({s[i], 1});
            }
            // checking at last as for i = n-1 case, checking initially doesn't work
            if(!st.empty() && st.top().second == k){
                for(int j=0; j<k; ++j){
                    st.pop();
                }
            }
            i--;
        }
        string res;
        while(!st.empty()){
            res += st.top().first;
            st.pop();
        }
        return res;
    }
};