

// DFS: O(q*n), O(q*h)
class Solution {
    map<string, vector<pair<string, double>>> g;
public:
    double isPath(string fr, string to, map<string, int>& vis){
        vis[fr] = 1;
        double dist = 1.0;
        if(fr == to && g.count(fr)) return dist;
        
        for(auto p: g[fr]){
            string cld = p.first;
            double p1 = p.second;
            
            if(!vis[cld]){
                double p2 = isPath(cld, to, vis);
                if(p2 != -1){
                    dist = p1*p2;
                    return dist;
                }
            }
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        
        for(int i=0; i<equations.size(); ++i){
            auto vs = equations[i];
            g[vs[0]].push_back({vs[1], values[i]});
            g[vs[1]].push_back({vs[0], 1.0/values[i]});
        }
        
        vector<double> ans;
        for(auto q: queries){
            map<string, int> vis;
            ans.push_back(isPath(q[0], q[1], vis));
        } 
        return ans;
    }
};