
// Pattern printing: O(r*c) O(1){excluding the res array}
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