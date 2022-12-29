


// Basic Multiplication: O(N*M)
// only trick is that ans is of max length m+n
// so we can store in an array of size m+n
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        if(num1 == "0" || num2 == "0") return "0";
        vector<int> ans(m+n, 0);
        for(int i=m-1; i>=0; --i){
            for(int j=n-1; j>=0; --j){
                int mltp = (num1[i]-'0') * (num2[j]-'0');
                // add prev carry
                mltp += ans[i+j+1];
                // value
                ans[i+j+1] = mltp % 10;
                // carry
                ans[i+j] += mltp / 10;
            }
        }
        string res;
        int f = 1;
        for(int i=0; i<m+n; ++i){
            if(f && ans[i] == 0) continue;
            else{
                f = 0;
                res += char(ans[i] + '0');
            }
        }
        return res;
    }
};