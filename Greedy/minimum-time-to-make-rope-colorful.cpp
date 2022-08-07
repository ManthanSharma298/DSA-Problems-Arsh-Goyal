

// Comparing with prev: O(n), O(1)
class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int t = 0;
        char prevColor = colors[0];
        int prevTime = time[0];
        for(int i=1; i<colors.size(); ++i){
            if(prevColor == colors[i]){
                int mn = min(prevTime, time[i]);
                int mx = max(prevTime, time[i]);
                t += mn;
                prevTime = mx;
            }
            else{
                prevColor = colors[i];
                prevTime = time[i];
            }
        }
        return t;
    }
};