class DirectedEulerianPath {
public:
    unordered_map<string, multiset<string>> graph;
    vector<string> path;

    void addEdge(const string& u, const string& v) {
        graph[u].insert(v);
    }

    void dfs(const string& u) {
        while (!graph[u].empty()) {
            string v = *graph[u].begin();
            graph[u].erase(graph[u].begin());
            dfs(v);
        }
        path.push_back(u);
    }

    vector<string> findEulerianPath() {
        string start = "JFK";
        dfs(start);
        reverse(path.begin(), path.end());

        return path;
    }
};

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        DirectedEulerianPath dep;

        for (const auto& ticket : tickets) {
            dep.addEdge(ticket[0], ticket[1]);
        }

        vector<string> result = dep.findEulerianPath();

        return result;
    }
};
