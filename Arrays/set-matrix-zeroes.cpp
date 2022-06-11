
// matricx traversal: O(r*c) O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int c = m[0].size(), r = m.size(), fg = 0, mrk;
        
        // checking for zero in first row
        for(int j=0; j<c; ++j){
            if(m[0][j] == 0){
                fg = 1;
                break;
            }
        }
        // for rows 
        for(int i=1; i<r; ++i){
            mrk = 0;
            for(int j=0; j<c; ++j){
                if(m[i][j] == 0){
                    m[0][j] = 0;
                    mrk = 1;
                }
            }
            if(mrk){
                for(int k=0; k<c; ++k){
                    m[i][k] = 0;
                }
            }
        }
        
        // for columns
        for(int j=0; j<c; ++j){
            if(m[0][j] == 0){
                for(int i=1; i<r; ++i){
                    m[i][j] = 0;
                }
            }
        }
        
        // for first row
        if(fg){
            for(int j=0; j<c; ++j){
                m[0][j] = 0;
            }
        }
    }
};

