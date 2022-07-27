

// Hard Problem: O(N*N), O(N*N)
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> path;
        for(int e: stones){
            unordered_set<int> s;
            path[e] = s;
        }
        path[0].insert(1);
        
        for(int i=0; i<stones.size(); ++i){
            for(int jump: path[stones[i]]){
                int pos = stones[i] + jump;
                if(pos == stones.back()) return true;
                
                auto it = path.find(pos);
                // if it contains in path
                if(it != path.end()){
                    if(jump - 1 > 0) it->second.insert(jump - 1);
                    it->second.insert(jump);
                    it->second.insert(jump + 1);
                }
            }
        }   
        return false;
    }
};