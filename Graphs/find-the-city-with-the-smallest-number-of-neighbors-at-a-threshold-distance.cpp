

// 1. Dikstras: O(n+e+n*(n+e)+n*n), O(n*n+n*e) -> excluding graph
class Solution {
    int inf = INT_MAX;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, inf));
        vector<vector<vector<int>> > g(n);
        for(int i=0; i<n; ++i) dist[i][i] = 0;
        for(auto e: edges){
            int s = e[0], d = e[1], cost = e[2];
            g[s].push_back({d, cost});
            g[d].push_back({s, cost});
        }
        for(int i=0; i<n; ++i){
            vector<int>& dd = dist[i];
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > pq; 
            pq.push({0, i});
            
            while(!pq.empty()){
                int sz = pq.size();
                while(sz--){
                    int node = pq.top().second;
                    pq.pop();
                    for(auto cld: g[node]){
                        int d = cld[0], cost = cld[1];
                        if(dd[node] + cost < dd[d]){
                            dd[d] = dd[node] + cost;
                            pq.push({dd[d], d});
                        }
                    }
                } 
            }
        }
        
        int mn = INT_MAX, city = n-1;
        for(int i=n-1; i>=0; --i){
            int curr = 0;
            for(int j=0; j<n; ++j){
                if(i != j && dist[i][j] <= distanceThreshold) curr++;
            }
            if(curr < mn){
                mn = curr;
                city = i;
            }
        }
        return city;
    }
};          


// 2. Floyd–Warshall algorithm: O(N^3), O(N^2)
class Solution {
    int inf = INT_MAX;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, inf));
        for(int i=0; i<n; ++i){
            dist[i][i] = 0;
        }
        for(auto e: edges){
            int s = e[0], d = e[1], cost = e[2];
            dist[s][d] = cost;
            dist[d][s] = cost;
        }
        
        for(int node=0; node<n; ++node){
            for(int i=0; i<n; ++i){
                for(int j=0; j<n; ++j){
                    if(i != j && dist[i][node] != inf && dist[node][j] != inf && dist[i][j] > dist[i][node] + dist[node][j]){
                        dist[i][j] = dist[i][node] + dist[node][j];
                    }
                }
            }
        }
        int mn = inf, city = n-1;
        for(int i=n-1; i>=0; --i){
            int curr = 0;
            for(int j=0; j<n; ++j){
                if(dist[i][j] <= distanceThreshold) curr++;
            }
            if(curr < mn){
                mn = curr;
                city = i;
            }
        }
        return city;
    }
};          
