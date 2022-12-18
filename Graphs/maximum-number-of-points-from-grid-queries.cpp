


// BFS + priority_queue + prefix sum
// O(r*c), O(r*c)
class Solution {
    struct cmp{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[2] > b[2];
        }
    };
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        set<pair<int,int>> vis;

        vector<pair<int, int>> q;
        for(int i=0; i<queries.size(); ++i){
            q.push_back(make_pair(queries[i], i));
        }
        sort(q.begin(), q.end());
        vector<int> dir = {-1, 0, 1, 0, -1};
        vector<int> ans(queries.size(), 0);
        pq.push({0, 0, grid[0][0]});
        vis.insert({0, 0});
        
        int cnt = 0;
        for(auto &p: q){
            int curr = p.first, id = p.second;
            while(!pq.empty()){
                auto e = pq.top();
                pq.pop();
                int x = e[0], y = e[1], val = e[2];
                if(curr <= val){
                    pq.push(e);
                    break;
                }
                cnt++;
                for(int i=0; i<4; ++i){
                    int xs = x + dir[i], ys = y + dir[i+1];
                    if(xs >= 0 && ys >= 0 && xs < grid.size() && ys < grid[0].size() &&
                    vis.find({xs, ys}) == vis.end()){
                        vis.insert({xs, ys});
                        pq.push({xs, ys, grid[xs][ys], 0});
                    }
                }
            }
            ans[id] = cnt;
        }
        return ans;
    }
};