

// Trying out all possible numbers: O(9^num_of_empty_cells), O(9) ~ O(1)
class Solution {
    int n = 9;
public:
    bool check(char v, int r, int c, vector<vector<char>>& board){
        for(int i=0; i<n; ++i){
            if(board[i][c] == v) return false;
            if(board[r][i] == v) return false;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3] == v) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j] == '.'){
                    // try all values
                    for(char val='1'; val<='9'; ++val){
                        if(check(val,i,j,board)){
                            board[i][j] = val;
                            if(solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    // if there is no valid solution
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// my solution: (although same but deserves a place)
class Solution {
public:
    bool check(int x, int y, char num, vector<vector<char>>& board){
        
        for(int i=0; i<9; ++i){
            if(board[i][y] == num) return false;
        }
        for(int j=0; j<9; ++j){
            if(board[x][j] == num) return false;
        }
        
        int r = x/3, c = y/3;
        r *= 3;
        c *= 3;
        
        for(int i=r; i<r+3; ++i){
            for(int j=c; j<c+3; ++j){
                if(board[i][j] == num) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] == '.'){
                    for(int num=1; num <= 9; ++num){
                        char ch = num + '0';
                        if(check(i, j, ch, board) == false) continue;
                        board[i][j] = ch;
                        if(solve(board)) return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {        
        solve(board);
    }
};