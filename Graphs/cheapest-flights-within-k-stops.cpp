

// (TLE)
// 1. bfs with pq: O(N + E*log(E*K)), O(N + E*K)-> excluding graph
class Solution {
    const int inf = 1e9;
public:
    struct comp{
        bool operator()(vector<int>& fst, vector<int>& sec){
            return fst[1] > sec[1];
        }
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int> >> g(n);
        for(auto e: flights){
            g[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        vector<int> dist(n, inf);
        dist[src] = 0;
        pq.push({src, 0, k+1});
        
        while(!pq.empty()){
            int sz = pq.size();
            for(int i=0; i<sz; ++i){
                int node = pq.top()[0], d = pq.top()[1], kk = pq.top()[2];
                pq.pop();

                if(kk > 0){
                    for(auto p: g[node]){
                        if(dist[p.first] > d+p.second){
                            dist[p.first] = d+p.second;
                        }
                        pq.push({p.first, d+p.second, kk-1});
                    }
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

// 2. bfs with queue: O(N + E), O(N + E)-> excluding graph
// as edges(or steps/K) are important not the weight so pq is not required
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int> >> g(n);
        for(auto e: flights){
            g[e[0]].push_back({e[1], e[2]});
        }
        queue<vector<int>> q;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        q.push({src, 0, k+1});
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; ++i){
                int node = q.front()[0], d = q.front()[1], kk = q.front()[2];
                q.pop();

                if(kk == 0) continue;
                for(auto p: g[node]){
                    if(dist[p.first] > d+p.second){
                        dist[p.first] = d+p.second;
                        q.push({p.first, d+p.second, kk-1});
                    }
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

// 3. Bellman-ford Algorithm: O((N+E)*K), O(N)
// can also be used in -ve edges
class Solution {
	const int inf = 1e9;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, inf);
        dist[src] = 0;
        
        for(int i=0; i<k+1; ++i){
        	vector<int> curr = dist;
        	for(auto e: flights){
        		int s=e[0], d=e[1], cost=e[2];
        		if(dist[s] != inf && dist[s]+cost < curr[d]){
        			curr[d] = dist[s] + cost;
        		}
        	}
        	dist = curr;
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};