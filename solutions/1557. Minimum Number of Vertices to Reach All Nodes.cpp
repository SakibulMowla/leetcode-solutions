// DFS

class Solution {
private:
    vector<vector<int>> adj;
    vector<int> par;
    vector<bool> visited;

    void buildGraph(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>> (n, vector<int>());
        for (auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        return;
    }

    void dfs(int node, int start) {
        par[node] = start;
        if (visited[node]) {
            return;
        }

        visited[node] = true;
        for (int next: adj[node]) {
            dfs(next, start);
        }

        return;
    }

public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        buildGraph(n, edges);
        par = vector<int> (n);
        visited = vector<bool> (n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, i);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (par[i] == i) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// ------------------------------------------------------------------------------------

// Greedy

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);

        for (auto& edge: edges) {
            inDegree[edge[1]]++;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
