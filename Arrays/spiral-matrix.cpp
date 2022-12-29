


// 1. Pattern printing: O(r*c) O(1){excluding the res array}
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int rw=m.size(), cl=m[0].size();
        int l=0, r=cl-1, u=0, d=rw-1;
        vector<int> res;
        
        while(l <= r && u <= d){
            // l to r
            for(int j=l; j<=r; ++j){
                res.push_back(m[u][j]);
            }
            u++;
            // u to d
            for(int i=u; i<=d; ++i){
                res.push_back(m[i][r]);
            }
            r--;
            // for {1,2,4} type array
            if(l > r || u > d) break;
            // r to l
            for(int j=r; j>=l; --j){
                res.push_back(m[d][j]);
            }
            d--;
            // d to u
            for(int i=d; i>=u; --i){
                res.push_back(m[i][l]);
            }
            l++;
        }
        return res;
    }
};

// 2. alternate approach(done by me): O(r*c), O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size()-1, top = 0, down = matrix.size()-1;
        vector<int> ans;
        while(left <= right && top <= down){
            // single column
            if(left == right){
                for(int i=top; i<=down; ++i){
                    ans.push_back(matrix[i][left]);
                }
            }
            // single row
            else if(top == down){
                for(int i=left; i<=right; ++i){
                    ans.push_back(matrix[top][i]);
                }
            }
            else{
                // right
                for(int i=left; i<right; ++i){
                    ans.push_back(matrix[top][i]);
                }
                for(int i=top; i<down; ++i){
                    ans.push_back(matrix[i][right]);
                }
                // left
                for(int i=right; i>left; --i){
                    ans.push_back(matrix[down][i]);
                }
                // up
                for(int i=down; i>top; --i){
                    ans.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            top++;
            down--;
        }
        return ans;
        
    }
};