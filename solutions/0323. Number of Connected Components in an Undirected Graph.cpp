class Solution {
public:
    void dfs(int cur, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[cur] = true;
        for (auto next: adj[cur]) {
            if (!visited[next]) {
                dfs(next, adj, visited);
            }
        }
        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int components = 0;
    
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, adj, visited);
            }
        }
        
        return components;
    }
};
