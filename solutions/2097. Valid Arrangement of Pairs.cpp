class Solution {
private:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> inDegree, outDegree;
    vector<int> path;

    void dfs(int u) {
        while (adj[u].size()) {
            int v = adj[u].back();
            adj[u].pop_back();
            dfs(v);
        }
        path.push_back(u);
    }

public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for (auto& pair: pairs) {
            adj[pair[0]].push_back(pair[1]);
            inDegree[pair[1]]++;
            outDegree[pair[0]]++;
        }

        int startNode = pairs[0][0];
        for (auto it: outDegree) {
            int out = it.second;
            int in = inDegree[it.first];
            if (out - in == 1)
                startNode = it.first;
        }

        dfs(startNode);

        reverse(path.begin(), path.end());

        vector<vector<int>> ans;
        for (int i = 1; i < path.size(); i++) {
            ans.push_back({path[i - 1], path[i]});
        }

        return ans;
    }
};
