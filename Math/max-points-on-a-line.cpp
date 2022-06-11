
// Brute force: O(n**2), O(1)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), mx=2, cnt;
        if(n == 1) return 1;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                cnt=0;
                for(int k=0; k<n && k!=i && k!=j; ++k){
                    if((points[j][1] - points[i][1])*(points[k][0] - points[i][0]) == (points[j][0] - points[i][0])*(points[k][1] - points[i][1])){
                        cnt++;
                    }
                }
                mx = max(mx, cnt+2);
            }
        }
        return mx;
    }
};