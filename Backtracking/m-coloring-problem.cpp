

// O(m^n), O(n+n)
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool dfs(int node, vector<int>& col, int m, int n, bool graph[101][101]){
        for(int i=0; i<n; ++i){
            if(graph[node][i]){
                if(col[i] != -1){
                    if(col[node] == col[i]) return false;
                }
                else{
                    for(int c=0; c<m; ++c){
                        col[i] = c;
                        if(dfs(i, col, m, n, graph)) return true;
                    }
                }
            }
        }    
        return true;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> col(m, -1);
        col[0] = 0;
        return dfs(0, col, m, n, graph);
    }
};
