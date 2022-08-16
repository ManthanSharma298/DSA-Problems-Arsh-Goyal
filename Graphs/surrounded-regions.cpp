

// Boundary DFS: O(N*M), O(N*M)
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board){
        int r = board.size(), c = board[0].size();
        if(i<0 || j<0 || i>=r || j>=c || board[i][j] != 'O') return;
        
        board[i][j] = '#';
        dfs(i+1, j, board);
        dfs(i-1, j, board);
        dfs(i, j+1, board);
        dfs(i, j-1, board);
        
    }
    void solve(vector<vector<char>>& board) {
        int r = board.size(), c = board[0].size();

        for(int j=0; j<c; ++j){
            if(board[0][j] == 'O') dfs(0, j, board);
        }
        for(int i=0; i<r; ++i){
            if(board[i][0] == 'O') dfs(i, 0, board);
        }
        for(int i=0; i<r; ++i){
            if(board[i][c-1] == 'O') dfs(i, c-1, board);
        }
        for(int j=0; j<c; ++j){
            if(board[r-1][j] == 'O') dfs(r-1, j, board);
        }
        
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(board[i][j] == '#') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};