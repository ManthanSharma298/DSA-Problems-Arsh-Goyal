
// IMPORTANT: LEAF NODES ARE IN IN-ORDER TRAVERSAL WHICH MEANS WE CAN'T CHANGE THEIR POSITION

// 1. DP + memo: O(n^3 + n^2), O(n^2)
// N* N^2 for building map first time
class Solution {
    map<pair<int,int>, pair<int,int> > dp;
public:
// returns {minSum, maxLeaf}
    pair<int, int> rec(int l, int r, vector<int>& a){
        // base condition
        if(l == r) return {0, a[l]};
        if(dp.count({l,r})) return dp[{l,r}];
        
        int minSum = INT_MAX, maxLeaf = INT_MIN;
        
        for(int i=l; i<r; ++i){
            auto lf = rec(l, i, a);
            auto rt = rec(i+1, r, a);

            maxLeaf = max(lf.second, rt.second);
            minSum = min(minSum, lf.first + rt.first + lf.second*rt.second);
        }
        return dp[{l,r}] = {minSum, maxLeaf};
        
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        return rec(0, n-1, arr).first;
    }
};

// monotonic stack: O(n), O(n)
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> st;
        st.push_back(INT_MAX);

        int cost = 0;
        for(int &rt: arr){
            while(rt >= st.back()){
                int num = st.back();
                st.pop_back();
                cost += min(st.back(), rt)*num;
            }
            st.push_back(rt);
        }
        // now what remains is a decreasing array
        for(int i=1; i<=st.size()-2; ++i){
            cost += st[i]*st[i+1];
        }
        return cost;
    }
};