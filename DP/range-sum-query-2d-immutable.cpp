

// Prefix sum in matrix: O(r*c/num_of_calls), O(r*c) 
class NumMatrix {
    vector<vector<int>> m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        m.resize(r+1, vector<int> (c+1, 0));
        
        for(int i=1; i<=r; ++i){
            int prev = 0;
            for(int j=1; j<=c; ++j){
                prev = prev + matrix[i-1][j-1];
                m[i][j] = prev;
                m[i][j] += m[i-1][j];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        r1++, c1++, r2++, c2++;
        
        int tot = m[r2][c2];
        int top = m[r1-1][c2];
        int left = m[r2][c1-1];
        int diag = m[r1-1][c1-1];
        
        return tot - left - top + diag;
    }
};