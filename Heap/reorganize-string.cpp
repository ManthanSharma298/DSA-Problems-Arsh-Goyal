

// k: number of distinct characters
// max-heap: O(k+k*log(k)), O(k+k)
class Solution {
public:
    string reorganizeString(string s) {
        string res;
        priority_queue<pair<int, char>> q;
        unordered_map<char, int> f;
        
        for(char ch: s) f[ch]++;
        
        for(auto p: f){
            q.push({p.second, p.first});
        }
        pair<int, char> dft = {0, '#'};
        pair<int, char> prev = dft;
        
        while(!q.empty() || prev != dft){
            if(q.empty()) return "";
            
            int cnt = q.top().first;
            char curr = q.top().second;
            q.pop();
            
            if(prev.second != curr){
                res += curr;
                cnt--;
                if(prev != dft){
                    q.push(prev);
                    prev = dft;
                }
                if(cnt > 0) prev = {cnt, curr};
            }
        }
        return res;
    }
};