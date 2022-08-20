

// BFS: O(n*n + 6), O(n*n + n*n)
class Solution {
public:
    pair<int, int> getIndex(int next, int n){
        int r, c;
        r = n-1 - (next-1)/n;
        c = (next-1) % n;
        if(r % 2 == n % 2) c = n-1-c;   // as we are starting from (n-1, 0) not (0, 0)
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q;
        vector<int> vis(n*n+1, 0);
        q.push(1);
        vis[1] = 1;
        
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int pos = q.front();
                q.pop();
                
                cout<<pos<<" "<<steps<<"\n";
                if(pos == n*n) return steps;    
                for(int i=1; i<=6; ++i){
                    int next = pos + i;
                    if(next > n*n) break;
                    if(vis[next]) continue;
                    // not visited
                    pair<int, int> p = getIndex(next, n);
                    int r = p.first, c = p.second;
                    
                    vis[next] = 1;
                    if(board[r][c] != -1) q.push(board[r][c]);
                    else q.push(next);
                }       
            }
            steps++;
        }
        return -1;
    }
};