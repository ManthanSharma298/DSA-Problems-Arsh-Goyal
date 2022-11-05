


// 1. Brute force
// iterate thrice: O(3*9*9), O(1)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& m) {
        for(int i=0; i<9; ++i){
            vector<int> vis(10,0);
            for(int j=0; j<9; ++j){
                if(m[i][j] != '.' && vis[m[i][j]-'0'] == 1) return false;
                else if(m[i][j] != '.') vis[m[i][j]-'0'] = 1;
            }
        }
        for(int i=0; i<9; ++i){
            vector<int> vis(10,0);
            for(int j=0; j<9; ++j){
                if(m[j][i] != '.' && vis[m[j][i]-'0'] == 1) return false;
                else if(m[j][i] != '.') vis[m[j][i]-'0'] = 1;
            }
        }
        for(int sx=0; sx<9; sx+=3){
            for(int sy=0; sy<9; sy+=3){
                vector<int> vis(10,0);
                
                for(int xx=0; xx<3; ++xx){
                    for(int yy=0; yy<3; ++yy){
                        if(m[sx+xx][sy+yy] != '.' && vis[m[sx+xx][sy+yy]-'0'] == 1) return false;                                 
                        else if(m[sx+xx][sy+yy] != '.') vis[m[sx+xx][sy+yy]-'0'] = 1;
                    }
                }
            }
        }
        
        return true;
    }
};


// 2. Hashset: O(9*9), O(9*9*3)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rs[9][9] = {0};
        int cs[9][9] = {0};
        int bs[9][9] = {0};
        
        
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] == '.') continue;
                int id = (i/3)*3 + j/3;
                int num = board[i][j] - '0' - 1;
                
                if(rs[i][num] || cs[j][num] || bs[id][num]){
                    return false;
                }
                rs[i][num] = 1;
                cs[j][num] = 1;
                bs[id][num] = 1;
            }
        }
        return true;
    }
};