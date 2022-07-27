
// k = 26 viz distinct number of elements
// max heap: O(n+k+n), O(k+k*n)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> f;
        for(auto ch: tasks) f[ch]++;
        
        priority_queue<int> pq;
        for(auto e: f){
            pq.push(e.second);
        }
        int time = 0;
        while(!pq.empty()){
            int sz = pq.size();
            vector<int> tmp;
            for(int i=0; i<min(n+1, sz); ++i){
                int curr = pq.top();
                pq.pop();
                   
                tmp.push_back(curr-1);
            }
            int v = tmp.size();
            for(int e: tmp){
                if(e > 0) pq.push(e);
            }
            time += pq.empty() ? v : n+1;
        }
        return time;
    }
};