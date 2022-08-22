

// Using elements from max-heap when required: O(n), O(n)
class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>& a, pair<int,int>& b){
            return a.first < b.first;
        }  
    };
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int pos = 0, fuel = startFuel;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        int n = stations.size(), i = 0, req = 0;
        while(i < n){
            int currPos = stations[i][0], currFuel = stations[i][1];
            if(pos + fuel < currPos){
                if(!pq.empty()){
                    auto tp = pq.top();
                    pq.pop();
                    
                    // fuel used
                    fuel -= tp.second-pos;
                    // fuel refilled
                    fuel += tp.first;
                    // update position
                    pos = tp.second;
                    req++;
                }
                else{
                    return -1;
                }
            }
            else{
                pq.push({currFuel, currPos});
                i++;
            }
        }
        while(pos + fuel < target){
            if(!pq.empty()){
                auto tp = pq.top();
                pq.pop();

                // fuel used
                fuel -= tp.second-pos;
                // fuel refilled
                fuel += tp.first;
                // update position
                pos = tp.second;
                req++;
            }
            else{
                return -1;
            }
        }
        return req;
    }
}; 