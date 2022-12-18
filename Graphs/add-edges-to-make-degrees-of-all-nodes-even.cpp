


class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> in(n+1);
        vector<int> nodes;
        set<pair<int, int>> st;
        for(auto e: edges){
            in[e[0]]++;
            in[e[1]]++;
            st.insert(make_pair(e[0], e[1]));
            st.insert(make_pair(e[1], e[0]));
        }
        for(int i=1; i<=n; ++i){
            if(in[i] % 2 == 1) nodes.push_back(i);
        }
        if(nodes.size() == 0) return true;
        if(nodes.size() == 2){
            int a = nodes[0], b = nodes[1];
            pair<int, int> p = {a, b};
            // self
            if(st.find(p) == st.end()) return true;

            for(int i=1; i<=n; ++i){
                if(i == a || i == b) continue;
                // a-i, b-i
                pair<int, int> p1 = {a, i};
                pair<int, int> p2 = {b, i};
                if(st.find(p1) == st.end() && st.find(p2) == st.end()) return true;
            }
        }
        if(nodes.size() == 4){
            int a = nodes[0], b = nodes[1], c = nodes[2], d = nodes[3];
            // self
            if((st.find({a, b}) == st.end() && st.find({c, d}) == st.end()) || 
                (st.find({a, c}) == st.end() && st.find({b, d}) == st.end()) || 
                (st.find({a, d}) == st.end() && st.find({b, c}) == st.end())){
                return true;
            }
            // others 
            // need atleast 4 edges but we can add atmost 2  
        }
        return false;
    }
};