class Edge {
public:
    int u, v, w;

    Edge(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

class MST {
private:
    int n;
    vector<Edge> edges;
    vector<int> parent;
    vector<int> rank;

public:
    MST(int n) : n(n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    void addEdge(int u, int v, int w) {
        edges.push_back(Edge(u, v, w));
    }

    int findParent(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    void unionSets(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if (parentU == parentV) {
            return;
        }

        if (rank[parentU] < rank[parentV]) {
            swap(parentU, parentV);
        }
        parent[parentV] = parentU;
        rank[parentU] += rank[parentV];
    }

    int findMinCost() {
        sort(edges.begin(), edges.end());
        
        int totalCost = 0;
        int edgeNeeded = n - 1;

        for (int i = 0; i < edges.size() && edgeNeeded; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;

            // Check if u and v are already connected
            if (findParent(u) != findParent(v)) {
                unionSets(u, v);
                totalCost += w;
                edgeNeeded--;
            }
        }

        return totalCost;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        MST mst(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                mst.addEdge(i, j, weight);
            }
        }

        return mst.findMinCost();
    }
};
