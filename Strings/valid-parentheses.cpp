
// Using stack: O(n), O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char &ch: s){
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else{
                if(st.empty()) return false;
                if(ch == ')'){
                    if(st.top() == '(') st.pop();
                    else return false;
                }
                if(ch == '}'){
                    if(st.top() == '{') st.pop();
                    else return false;
                }
                if(ch == ']'){
                    if(st.top() == '[') st.pop();
                    else return false;
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};