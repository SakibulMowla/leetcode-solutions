class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);

        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }

        int remaining = n;
        while (remaining > 2) {
            int leavesCount = leaves.size();
            remaining -= leavesCount;
            for (int i = 0; i < leavesCount; i++) {
                int leaf = leaves.front();
                leaves.pop();

                for (int next: adj[leaf]) {
                    degree[next]--;
                    if (degree[next] == 1) {
                        leaves.push(next);
                    }
                }
            }
        }

        vector<int> ans;
        while (!leaves.empty()) {
            ans.push_back(leaves.front());
            leaves.pop();
        }

        return ans;
    }
};
