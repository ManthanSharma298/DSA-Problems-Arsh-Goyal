// 1. Brute force: O(n**2), O(1)

// 2. Priority queue: O(n*logn), O(n)
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size(),xi,yi,xx,diff;
        priority_queue<pair<int,int>> pq;
        int res = INT_MIN;
        
        for(int i=0; i<n; ++i){
            xi = points[i][0], yi = points[i][1];
            // as x are in sorted order so if xj-xi > k then it would also be greater of index greater than j
            while(!pq.empty() && xi - pq.top().second > k) pq.pop();
            if(!pq.empty()){
                diff = pq.top().first;
                res = max(res, xi+yi+diff);
            }
            pq.push(make_pair(yi - xi, xi));
        }
        return res;
    }
};