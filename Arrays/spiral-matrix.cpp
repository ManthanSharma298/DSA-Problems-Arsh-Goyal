


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
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = n-1, t = 0, b = m-1;
        while(l <= r || t <= b){
            // for single row
            if(t == b){
                for(int i=l; i<=r; ++i){
                    res.push_back(matrix[t][i]);
                }
                break;
            }
            // for single column
            if(l == r){
                for(int i=t; i<=b; ++i){
                    res.push_back(matrix[i][l]);
                }
                break;
            }
            if(l < r && t < b){
                for(int i=l; i<r; ++i){
                    res.push_back(matrix[t][i]);
                }
                for(int j=t; j<b; ++j){
                    res.push_back(matrix[j][r]);
                }
                for(int i=r; i>l && t<b; --i){
                    res.push_back(matrix[b][i]);
                }
                for(int j=b; j>t; --j){
                    res.push_back(matrix[j][l]);
                }
            }
            l++;
            r--;
            t++;
            b--;
        }
        return res;
    }
};