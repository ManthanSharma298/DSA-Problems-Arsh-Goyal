
// n: size of word
// O(r*c*4*n), O(n) -> stack size
class Solution {
public:
    bool check(vector<vector<char>>& board, string word, int x, int y, int i){
        if(i >= word.size()) return true;
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y] != word[i]) return false;
        board[x][y] = '#';
        
        
        bool res = check(board, word, x+1, y, i+1) || check(board, word, x, y+1, i+1) || 
            check(board, word, x-1, y, i+1) || check(board, word, x, y-1, i+1);
        
        board[x][y] = word[i];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size(), c=board[0].size();
        if(word.size() == 0) return false;
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(board[i][j] == word[0] && check(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};