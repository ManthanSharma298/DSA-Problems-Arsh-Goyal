

// using stack: O(n), O(n)
int evaluatePostfix(string S)
    {
        stack<int> st;
        for(int e: S){
            if(e == '+' || e == '-' || e == '*' || e == '/'){
                int s = st.top();
                st.pop();
                int f = st.top();
                st.pop();
                
                if(e == '+') st.push(f+s);
                else if(e == '-') st.push(f-s);
                else if(e == '*') st.push(f*s);
                else st.push(f/s);
            }
            else{
                st.push(e-'0');
            }
        }
        return st.top();
    }