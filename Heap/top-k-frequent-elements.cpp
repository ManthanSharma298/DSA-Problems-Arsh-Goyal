

// d is the number of distinct numbers
// min-Heap: O(n+d*logd), O(k+d)-> map & pq
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        for(int &num: nums){
            f[num]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        for(auto e: f){
            if(pq.size() < k) pq.push({e.second, e.first});
            else{
                if(e.second > pq.top().first){
                    pq.pop();
                    pq.push({e.second, e.first});
                }
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};