

// max-heap of size k: O(n+k), O(k) -> excluding res array
class Solution {
public:
    struct comp{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[0] < b[0]; // increasing for min pq
        }  
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        int curr;
        for(auto pt: points){
            int x = pt[0], y = pt[1];
            curr = x*x + y*y;
            if(pq.size() < k){
                pq.push({curr, x, y});
            }
            else if(pq.top()[0] > curr){
                pq.pop();
                pq.push({curr, x, y});
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            int x = pq.top()[1], y = pq.top()[2];
            pq.pop();
            res.push_back({x, y});
        }
        return res;
    }
};