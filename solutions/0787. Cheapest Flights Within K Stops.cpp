struct Node {
    int city, stops, cost;
    Node(int city, int stops, int cost): city(city), stops(stops), cost(cost) {}

    bool operator < (const Node& other) const {
        return cost > other.cost;
    }
};

class Solution {
private:
    void buildAdjacency(vector<vector<int>>& flights, vector<vector<pair<int, int>>>& adj) {
        for (auto flight: flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        return;
    }

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        buildAdjacency(flights, adj);

        vector<int> stops(n, INT_MAX);
        stops[src] = 0;

        priority_queue<Node> nodes;
        nodes.push(Node(src, 0, 0));

        while (!nodes.empty()) {
            auto cur = nodes.top();
            nodes.pop();

            if (cur.stops > k + 1 || cur.stops > stops[cur.city]) {
                continue;
            }

            if (cur.city == dst) {
                return cur.cost;
            }

            stops[cur.city] = cur.stops;

            for (auto next: adj[cur.city]) {
                nodes.push(Node(next.first, cur.stops + 1, cur.cost + next.second));
            }
        }

        return -1;
    }
};
