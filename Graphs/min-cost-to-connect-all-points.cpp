

// Prim's Algo
// Minimum Spanning Tree
// O(E*log(E)), O(E)
// E ~ N*N

class Solution {
    struct cmp{
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
        }
    };
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        int n = points.size(), ans = 0;
        unordered_set<int> vis;

        pq.push(make_pair(0, 0));
        while(!pq.empty() && vis.size() < n){
            int node = pq.top().first, d = pq.top().second;
            pq.pop();
            if(vis.find(node) != vis.end()) continue;

            vis.insert(node);
            for(int i=0; i<n; ++i){
                if(vis.find(i) == vis.end()){
                    pq.push(make_pair(i, abs(points[i][0]-points[node][0]) + abs(points[i][1]-points[node][1])));
                }
            }
            ans += d;
        }
        return ans;
    }
};