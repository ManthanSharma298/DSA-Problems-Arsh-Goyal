

// we can also use stack: O(N), O(N)
// Traversal: O(N), O(1)
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size(), cnt = 1, id = n-1;
        double time;
        // need to sort
        vector<pair<int,int>> a;
        for(int i=0; i<n; ++i){
            a.push_back({position[i], speed[i]});
        }
        sort(a.begin(), a.end());
        
        for(int i=n-2; i>=0; i--){
            if(a[id].second == a[i].second){
                if(a[id].first != a[i].first){
                    cnt++;
                    id = i;
                }
            }
            else{
                time = (double)(a[i].first- a[id].first) / (a[id].second - a[i].second);
                if(time < 0 || a[id].first + time*a[id].second > target){
                    cnt++;
                    id = i;
                }
            }
        }
        return cnt;
    }
}; 