// 1. Brute force: O(n**2), O(1)

// 2. using array and stack: O(5*n), O(3*n)
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size(), res = 0;;
        stack<int> st;
        vector<int> l(n), r(n);
        
        for(int i=0; i<n; ++i){
            while(!st.empty() && h[st.top()] >= h[i]){
                st.pop();
            }
            if(st.empty()){
                l[i] = 0;
            }
            else{
                l[i] = st.top()+1;
            }
            st.push(i);    
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=n-1; i>=0; --i){
            while(!st.empty() && h[st.top()] >= h[i]){
                st.pop();
            }
            if(st.empty()){
                r[i] = n-1;
            }
            else{
                r[i] = st.top()-1;
            }
            st.push(i);
        }
        
        for(int  i=0; i<n; ++i){
            res = max(res, (r[i]-l[i]+1)*h[i]);
        }
        
        return res;
    }
};

// 3. Brute force: O(n), O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size(), res = 0, tp, rt, lf;
        stack<int> st;
        
        for(int i=0; i<n; ++i){
            while(!st.empty() && h[st.top()] >= h[i]){
                tp = st.top(), rt = i-1, lf;
                st.pop();
                
                lf = (st.empty() ? 0 : st.top()+1);
                
                res = max(res, (rt-lf+1)*h[tp]);
            }
            st.push(i);    
        }
        // for remaining elements in stack
        rt = n-1;
        while(!st.empty()){
            tp = st.top();
            st.pop();
            
            lf = (st.empty() ? 0 : st.top()+1);
            res = max(res, (rt-lf+1)*h[tp]);
        }
        
        return res;
    }
};