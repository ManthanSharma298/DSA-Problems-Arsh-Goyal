

// 1. Reverse and transpose: O(2*n*n), O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();

        // reverse the matrix
        reverse(m.begin(), m.end());
        // transpose of matrix
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                swap(m[i][j], m[j][i]);
            }
        }
    }
};


// 2. Using two pointers: O(n*n), O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size(), l = 0, r = n-1;
        while(l < r){
            int tmp;
            for(int i=l; i<r; ++i){
                // assigning values
                // top = m[l][i];
                // tmp = top;
                // left = m[n-i-1][l];
                // right = m[i][r];
                // bottom = m[r][n-i-1];
                
                // rotation
                tmp = m[l][i];
                // top = left;
                m[l][i] = m[n-i-1][l];
                // left = bottom;
                m[n-i-1][l] = m[r][n-i-1];
                // bottom = right;
                m[r][n-i-1] = m[i][r];
                // right = tmp;
                m[i][r] = tmp;
            }
            l++;
            r--;
        }
    }
};