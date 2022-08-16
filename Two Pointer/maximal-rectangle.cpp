

// prefix matrix + max-area-in-histogram: O(n*m + n*m), O(2*n*m) -> dp + n times creating a stack
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for(int j=0; j<col; ++j){
            for(int i=0; i<row; ++i){
                if(i == 0){
                    dp[i][j] = matrix[i][j] - '0';
                }
                else{
                    if(matrix[i][j] == '0'){
                        dp[i][j] = 0;
                    }
                    else{
                        dp[i][j] = dp[i-1][j] + (matrix[i][j] - '0');
                    }
                }
            }
        }
        int MAX = 0;
        for(int j=0; j<row; ++j){
            stack<int> s;
        
            int n = dp[j].size(), mx = 0, curr, l, r;
            for(int i=0; i<n; ++i){
                while(!s.empty() && dp[j][s.top()] >= dp[j][i]){
                    int id = s.top();
                    s.pop();

                    l = (s.empty() ? 0 : s.top()+1);
                    r = i-1;

                    curr = dp[j][id] * (r-l+1);
                    mx = max(mx, curr);
                }  
                s.push(i);
            }

            r = n-1;
            while(!s.empty()){
                int id = s.top();
                s.pop();

                l = (s.empty() ? 0 : s.top()+1);

                curr = dp[j][id] * (r-l+1);
                mx = max(mx, curr);
            }

            MAX = max(MAX, mx);
        }
        
        return MAX;
    }
};