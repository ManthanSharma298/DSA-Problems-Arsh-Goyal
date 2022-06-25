

// Monotonic stack: O(n), O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> ms;
        int n = temperatures.size();
        vector<int> res(n, 0);

        for(int i=0; i<n; ++i){
            while(!ms.empty() && temperatures[i] > temperatures[ms.top()]){
                res[ms.top()] = i - ms.top();
                ms.pop();
            }
            ms.push(i);
        }
        return res;
    }
};