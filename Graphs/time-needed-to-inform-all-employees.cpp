

// 1. DFS: (from root to leaf): O(n), O(n+n) -> adj list
class Solution {
    vector<int> informTime;
    unordered_map<int, vector<int>> g; 
public:
    int mtime(int id){
        int mx = 0;
        for(int cld: g[id]){
            mx = max(mx, mtime(cld));
        }
        return mx + informTime[id];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        this->informTime = informTime;
        
        for(int i=0; i<n; ++i){
            if(manager[i] != -1){
                g[manager[i]].push_back(i);
            }
        }
        vector<int> vis(n, 0);
        return mtime(headID);
    }    
};


// 2. Efficient DFS: O(n), O()
class Solution {
    vector<int> informTime;
    vector<int> manager;
public:
    int up(int id){
        if(manager[id] != -1){
            informTime[id] += up(manager[id]);
            manager[id] = -1;
        }
        return informTime[id];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        this->informTime = informTime;
        this->manager = manager;
        
        int mx = 0;
        // running dfs on clds
        for(int i=0; i<n; ++i){
            mx = max(mx, up(i));
        }
        return mx;
    }    
};