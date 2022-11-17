

// Min-Heap: O((k+candidates)*log(candidates)), O(2*candidates)

#define ll long long 
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        ll ans = 0;
        priority_queue<int, vector<int>, greater<int>> p, q;
        int n = costs.size(), l = 0, r = n-1;
        
        while(k--){
            while(p.size() < candidates && l <= r){
                p.push(costs[l++]);
            }
            while(q.size() < candidates && l <= r){
                q.push(costs[r--]);    
            }
            if(p.empty()){
                ans += q.top();
                q.pop();
            }
            else if(q.empty()){
                ans += p.top();
                p.pop();
            }
            else if(p.top() <= q.top()){
                ans += p.top();
                p.pop();
            }
            else{
                ans += q.top();
                q.pop();
            }
        }
        return ans;
    }
};