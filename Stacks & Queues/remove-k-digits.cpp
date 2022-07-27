

// monotonic-stack: O(n+k), O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        // edge case
        if(num.size() == k) return "0";
        
        stack<int> s;
        
        for(int i=0; i<num.size(); ++i){
            int curr = num[i] - '0';
            while(!s.empty() && s.top() > curr && k > 0){
                s.pop();
                k--;
            }
            s.push(curr);
        }
        string res;
        while(k--){
            s.pop();
        }
        while(!s.empty()){
            char ch = s.top() + '0';
            res += ch;
            s.pop();
        }
        // edge case
        while(res.size() > 1 && res.back() == '0'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};