


class Solution {
public:
    // ANSWER OF 3+5*3/2 IS 10 NOT 7 
    int calculate(string s) {
        stack<int> st;
        int n = s.size();
        int curr = 0;
        char sign = '+';
        for(int i=0; i<n; ++i){
            // for digit
            if(s[i] != ' ' && s[i]-'0' >= 0 && s[i]-'0' <= 9){
                curr = curr*10 + (s[i]-'0');
            }
            // for sign
            if((s[i] != ' ' && s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') ||i == n-1){
                if(sign == '+'){
                    st.push(curr);
                }
                else if(sign == '-'){
                    st.push(-curr);
                }
                else if(sign == '*'){
                    int tp = st.top();
                    st.pop();
                    st.push(tp*curr);
                }
                else{
                    int tp = st.top();
                    st.pop();
                    st.push(tp/curr);  
                }
                curr = 0;
                sign = s[i];
            }
        }
        int res = 0;
        while(st.size() >= 2){
            int tp = st.top();
            st.pop();
            int stp = st.top();
            st.pop();
            
            st.push(stp + tp);
        }
        
        return st.top();
    }
};