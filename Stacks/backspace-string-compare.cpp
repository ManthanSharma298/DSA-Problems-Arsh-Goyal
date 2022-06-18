

// 1. using stacks: O(n+m), O(n+m)
class Solution {
public:
    string fillStack(string s){
        stack<char> st;
        for(char &ch: s){
            if(ch == '#'){
                if(!st.empty()) st.pop();
            }
            else st.push(ch);
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
    bool backspaceCompare(string s, string t) {
        s = fillStack(s);
        t = fillStack(t);

        return s == t;
    }
};

// 2. two pointers: O(max(n, m)): O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size(), m = t.size();
        int i = n-1, j = m-1, cnt;
        
        while(i >= 0 && j >= 0){
            if(s[i] != '#' && t[j] != '#'){
                if(s[i--] != t[j--]) return false;
            }
            else{
                cnt = 0;
                while(i >= 0 && (cnt > 0 || s[i] == '#')){
                    if(s[i] == '#') cnt++;
                    else cnt--;
                    i--;
                }
                
                cnt = 0; 
                while(j >= 0 && (cnt > 0 || t[j] == '#')){
                    if(t[j] == '#') cnt++;
                    else cnt--;
                    j--;
                }
            }
        }
        if(j >= 0){
            cnt = 0; 
            while(j >= 0 && (cnt > 0 || t[j] == '#')){
                if(t[j] == '#') cnt++;
                else cnt--;
                j--;
            }
        }
        if(i >= 0){
            cnt = 0;
            while(i >= 0 && (cnt > 0 || s[i] == '#')){
                if(s[i] == '#') cnt++;
                else cnt--;
                i--;
            }
        }
        if(i >= 0 || j >= 0) return false;
        return true;
            
    }
};
