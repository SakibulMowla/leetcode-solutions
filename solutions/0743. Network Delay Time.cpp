class Solution {
public:
    struct Data {
        int to;
        int cost;
        Data (int to, int cost): to(to), cost(cost) {}
        bool operator < (const Data& x) const {
            return x.cost < cost;
        }
    };
    
    int dijkstra(int N, int K, vector<vector<Data>>& G) {
        vector<int> dist(N + 1, numeric_limits<int>::max());
        dist[K] = 0;
        
        priority_queue<Data> pq;
        pq.push(Data(K, 0));
        
        while (!pq.empty()) {
            Data u = pq.top();
            pq.pop();
            
            for (auto& v: G[u.to]) {
                if (dist[v.to] > u.cost + v.cost) {
                    pq.push(Data(v.to, u.cost + v.cost));
                    dist[v.to] = u.cost + v.cost;
                }
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            ans = max(ans, dist[i]);
        }
        
        return ans == numeric_limits<int>::max() ? - 1 : ans;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<Data>> G(N + 1, vector<Data>());
        for (auto& entry: times) {
            G[entry[0]].push_back(Data(entry[1], entry[2]));
        }
        
        return dijkstra(N, K, G);
    }
};
