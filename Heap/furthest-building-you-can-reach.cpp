

// k: number of ladders
// Using heap: O(n*logk), O(k)
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=1; i<n; ++i){
            int diff = heights[i] - heights[i-1];
            if(diff > 0){
                if(pq.size() < ladders){
                    // use ladders
                    pq.push(diff);
                }
                else{
                    // use bricks
                    pq.push(diff);
                    int mnDist = pq.top();
                    pq.pop();
                    
                    if(bricks < mnDist) return i-1;
                    bricks -= mnDist;
                }
            }
        }
        return n-1;
    }
};