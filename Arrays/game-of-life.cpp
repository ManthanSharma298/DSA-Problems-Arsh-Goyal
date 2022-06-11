// 1. Using external storage: O(8*r*c), O(r*c)

// 2. denoting with different numbers: O(9*r*c), O(1)

class Solution {
public:
    // Rules
    // 1 -> 0 if l < 2
    // 1 -> 1 if l = 2,3
    // 1 -> 0 if l > 3
    // 0 -> 1 if l = 3
    
    // 1 -> change -> -1
    // 0 -> change -> -2
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dir[] = {{1,0},{0,1},{1,1},{-1,-1},{0,-1},{-1,0},{1,-1},{-1,1}};
        int r=board.size(), c=board[0].size(), cnt;
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                cnt=0;
                for(auto v: dir){
                    if(i+v[0] < r && j+v[1] < c && i+v[0] >= 0 && j+v[1] >= 0){
                        if(board[i+v[0]][j+v[1]] == 1) cnt++;
                        if(board[i+v[0]][j+v[1]] == -1) cnt++;                        
                    }
                }
                if(board[i][j] == 0){
                    if(cnt == 3) board[i][j] = -2;
                }
                else{
                    if(cnt < 2 || cnt > 3) board[i][j] = -1;
                }
            }
        }
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(board[i][j] == -1) board[i][j] = 0;
                else if(board[i][j] == -2) board[i][j] = 1;
            }
        }
    }
};