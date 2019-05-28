class Solution {
public:
    double dfs(int now, int target, vector<vector<int>>& edges, vector<vector<double>>& costs, vector<bool>& col) {
        if (now == target) {
            return 1.0;
        }
        
        col[now] = true;
        
        int n = edges[now].size();
        for (int i = 0; i < n; i++) {
            int v = edges[now][i];
            if (!col[v]) {
                double ret = dfs(v, target, edges, costs, col);
                if (ret != -1) {
                    return ret * costs[now][i];
                }
            }
        }
        
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nodes = 0;
        int n = equations.size();
        vector<vector<int>> edges;
        vector<vector<double>> costs;
        unordered_map<string, int> nodeNumber;

        for (int i = 0; i < n; i++) {
            if (nodeNumber.find(equations[i][0]) == nodeNumber.end()) {
                nodeNumber[equations[i][0]] = nodes++;
                edges.push_back(vector<int>());
                costs.push_back(vector<double>());
            }

            if (nodeNumber.find(equations[i][1]) == nodeNumber.end()) {
                nodeNumber[equations[i][1]] = nodes++;
                edges.push_back(vector<int>());
                costs.push_back(vector<double>());
            }
    
            int u = nodeNumber[equations[i][0]];
            int v = nodeNumber[equations[i][1]];

            edges[u].push_back(v);
            costs[u].push_back(values[i]);
            
            edges[v].push_back(u);
            costs[v].push_back(1.0 / values[i]);
        }
        
        vector<double> ans;

        for (auto& query: queries) {
            vector<bool> col(nodes, false);
            if (nodeNumber.find(query[0]) == nodeNumber.end() || nodeNumber.find(query[1]) == nodeNumber.end()) {
                ans.push_back(-1);
            } else {
                ans.push_back(dfs(nodeNumber[query[0]], nodeNumber[query[1]], edges, costs, col));   
            }
        }
        
        return ans;
    }
};
