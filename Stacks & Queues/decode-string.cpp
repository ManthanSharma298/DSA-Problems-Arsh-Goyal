

// 1. Using Recursion: O(n*n), O(n)
class Solution {
public:
    string decodeString(string s) {
        string res = "";
        int n = s.size();
        int i=0;
        while(i < n){
            if(isdigit(s[i])){
                int dig = 0;
                while(i<n && s[i] != '['){
                    dig = dig*10 + s[i]-'0';
                    i++;
                }
                i++;
                int bk = 1;
                string tmp = "";
                while(i<n && bk > 0){
                    if(s[i] == '['){
                        bk++;
                        tmp += s[i];
                    }
                    else if(s[i] == ']'){
                        bk--;
                        if(bk > 0) tmp += s[i];
                    }
                    else tmp += s[i];
                    i++;
                }
                tmp = decodeString(tmp);
                while(dig--){
                    res += tmp;
                }
            }
            else{
                res += s[i++];
            }
        }
        
        return res;
    }
};

// 1.1 Optimised recursion: O(n), O(n)
class Solution {
public:
    string f(string &s, int &i) {
        string res;
        int n = s.size();

        while(i < n && s[i] != ']'){
            if(isdigit(s[i])){
                int dig = 0;
                while(i<n && isdigit(s[i])){
                    dig = dig*10 + s[i++]-'0';
                }
    
                i++; // for '['
                string tmp = f(s, i);
                i++; // for ']'
                
                while(dig--){
                    res += tmp;
                }
            }
            else{
                res += s[i++];
            }
        }
        
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return f(s, i);
    }
};


// 2. Stack: O(n), O(n)
class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        
        int num = 0;
        string curr;
        for(int i=0; i<s.size(); ++i){
            if(isdigit(s[i])){
                num = num*10 + s[i]-'0';
            }
            else if(s[i] == '['){
                st.push({curr, num});
                num = 0;
                curr = "";
            }
            else if(s[i] == ']'){
                string prev = st.top().first;
                int cnt = st.top().second;
                st.pop();
                
                while(cnt--){
                    prev += curr;
                }
                curr = prev;
            }
            else{
                curr += s[i];
            }
        }
        return curr;
    }
};
