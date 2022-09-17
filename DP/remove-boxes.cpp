

// rec + memo: O(n^3), O(n^3)
class Solution {
    int dp[100][100][100];
public:
    int rec(int l, int r, int cnt, vector<int>& boxes){
        if(l > r) return 0;
        
        if(dp[l][r][cnt] != 0) return dp[l][r][cnt];
        
        int mx = (cnt+1)*(cnt+1) + rec(l+1, r, 0, boxes);
        for(int i=l+1; i<=r; ++i){
            if(boxes[i] == boxes[l]){
                mx = max(mx, rec(i, r, cnt+1, boxes) + rec(l+1, i-1, 0, boxes));
            }
        }
        return dp[l][r][cnt] = mx;
    }
    
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(dp, 0, sizeof(dp));
        return rec(0, n-1, 0, boxes);
    }
};