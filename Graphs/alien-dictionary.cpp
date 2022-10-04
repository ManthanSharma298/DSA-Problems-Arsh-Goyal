

// Creating graph + Topological Sort: O(N*|S|+N+K), O(H) -> worst case O(N)
class Solution{
    public:
    string res;
    bool dfs(int node, vector<int>& vis, vector<int>& curr, vector<vector<int>>& g){
        vis[node] = 1;
        curr[node] = 1;
        
        for(int cld: g[node]){
            if(!vis[cld]){
                if(dfs(cld, vis, curr, g) == false) return false;
            }
            else{
                if(curr[cld] == 1) return false;
            }
        }
        char ch = node + 'a';
        res += ch;
        curr[node] = 0;
        return true;
    }
    
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> g(K);
        for(int i=0; i<N-1; ++i){
            string a = dict[i];
            string b = dict[i+1];
            
            int x=0, y=0;
            while(x<a.size() && y<b.size()){
                if(a[x] == b[y]){
                    x++;
                    y++;
                }
                else{
                    g[b[y]-'a'].push_back(a[x]-'a');
                    break;
                }
            }
        }
        res = "";
        vector<int> vis(K, 0);
        vector<int> curr(K, 0);
        for(int i=0; i<K; ++i){
            if(vis[i] == 0){
                if(dfs(i, vis, curr, g) == false) return res;
            }
        }
        // cout<<res<<" ";
        return res;
    }
};