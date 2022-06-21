

// backtrack + parenthesis checking: O(n*2^2n), O(n*2^2n)
class Solution {
    int n;
    vector<string> st;
public:
    bool isValid(string s){
        stack<int> ck;
        
        int i = 0;
        while(i < s.size()){
            if(s[i] == '(') ck.push(0);
            else{
                if(ck.empty()) return false;
                ck.pop();
            }
            i++;
        }
        return ck.empty();
    }
    
    void f(string s){
        int sz = s.size();
        
        if(sz == 2*n){
            if(isValid(s)) st.push_back(s);
            return;
        }
        
        s += '(';
        f(s);
        s.pop_back();
        
        s += ')';
        f(s);
        s.pop_back();
        
    }
    vector<string> generateParenthesis(int n) {
        this->n = n;
        string s = "";
        f(s);
        
        return st;
    }
};

// very comlx visit: https://leetcode.com/problems/generate-parentheses/solution
class Solution {
    int n;
    vector<string> st;
public:
    void f(int l, int r, string s){
        if(l > n || r > n || l < r) return;
        
        if(l == n && r == n){
            st.push_back(s);
            return;
        }

        
        s.push_back('(');
        f(l+1, r, s);
        s.pop_back();
        
        s.push_back(')');
        f(l, r+1, s);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        this->n = n;
        string s = "";
        f(0,0,s);
        
        return st;
    }
};