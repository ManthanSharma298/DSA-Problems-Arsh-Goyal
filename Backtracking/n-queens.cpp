

// Backtracking
class Solution {
public:
    vector<vector<string>> res;
    bool check(int i, int j, vector<string>& mat){
        int n = mat.size();
        // row
        for(int c=0; c<n; ++c){
            if(mat[i][c] == 'Q') return false;
        }
        // col
        for(int r=0; r<n; ++r){
            if(mat[r][j] == 'Q') return false;
        }
        int ti = i, tj = j;
        // down-right
        while(i < n && j < n){
            if(mat[i++][j++] == 'Q') return false;
        }
        i = ti, j = tj;
        // down-left
        while(i < n && j >= 0){
            if(mat[i++][j--] == 'Q') return false;
        }
        i = ti, j = tj;
        // up-left
        while(i >= 0 && j >= 0){
            if(mat[i--][j--] == 'Q') return false;
        }
        i = ti, j = tj;
        // up-right
        while(i >= 0 && j < n){
            if(mat[i--][j++] == 'Q') return false;
        }
        return true;
    }
    void dfs(int i, vector<string>& mat){
        int n = mat.size();
        if(i == n){
            res.push_back(mat);
            return;
        }
        
        for(int j=0; j<n; ++j){
            if(check(i, j, mat)){
                mat[i][j] = 'Q';
                dfs(i+1, mat);
                mat[i][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> mat(n, string(n, '.'));           
        dfs(0, mat);
        return res;
    }
};