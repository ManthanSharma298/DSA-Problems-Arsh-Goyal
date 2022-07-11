

// BFS: O(N**2 + 4), O(N**2)
// NEVER USE MAP FOR VISITED, AS N = 1000 GIVES TLE
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    queue<pair<int, int>> q;
	    vector<int> dir[] = {{2,1}, {2,-1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {1,-2}, {-1,-2}};
	    vector<vector<int>> vis(N, vector<int>(N, 0));
	    
	    // converting in 0 based indexing
	    q.push({KnightPos[0]-1, KnightPos[1]-1});
	    vis[KnightPos[0]-1][KnightPos[1]-1] = 1;
	    int moves = 0;
	    while(!q.empty()){
	        int n = q.size();
	        for(int j=0; j<n; ++j){
    	        auto pos = q.front();
    	        q.pop();
    	        
    	        if(pos.first == TargetPos[0]-1 && pos.second == TargetPos[1]-1){
    	            return moves;
    	        }
    	        for(int i=0; i<8; ++i){
    	            int x = pos.first+dir[i][0], y = pos.second+dir[i][1];
    	            if(x>=0 && x<N && y>=0 && y<N && vis[x][y] == 0){
    	                vis[x][y] = 1;
    	                q.push({x, y});
    	            }
    	        }
	        }
	        moves++;
	    }
	    return -1;
	}
};