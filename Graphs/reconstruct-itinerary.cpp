

// T.C. O(nodes + edges)
// S.C. O(nodes) + O(edges)

class Solution {
    map<string, multiset<string>> mp;
    vector<string> ans;
public:
    void dfs(string node){
        while(!mp[node].empty()){
            string cld = *mp[node].begin();
            mp[node].erase(mp[node].begin());
            dfs(cld);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket: tickets){
            mp[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};