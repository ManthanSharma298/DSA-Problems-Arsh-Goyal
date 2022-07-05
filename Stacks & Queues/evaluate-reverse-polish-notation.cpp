

// Using Stack: O(n), O(n)
class Solution {
public:
    int conv(string s){
        int res = 0;
        int i = 0, n = s.size();
        int fg = 1;
        if(s[0] == '-'){
            fg = -1;
            i++;
        }
        while(i < n){
            res *= 10;
            res += (s[i] - '0');
            i++;
        }
        return fg*res;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int i = 0;
        for(string &s: tokens){
            if(s == "+"){
                int sec = st.top();
                st.pop();
                int fir = st.top();
                st.pop();
                
                st.push(fir+sec);
            }
            else if(s == "-"){
                int sec = st.top();
                st.pop();
                int fir = st.top();
                st.pop();
                
                st.push(fir-sec);
            }
            else if(s == "*"){
                int sec = st.top();
                st.pop();
                int fir = st.top();
                st.pop();
                
                st.push(fir*sec);
            }
            else if(s == "/"){
                int sec = st.top();
                st.pop();
                int fir = st.top();
                st.pop();
                
                st.push(fir/sec);
            }
            else{
                st.push(conv(s));
            }
        }
        return st.top();
    }
};