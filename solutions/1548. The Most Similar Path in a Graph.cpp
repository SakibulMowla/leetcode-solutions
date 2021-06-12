class Solution {
private:
int findMinEditDistance(int len, vector<vector<int>>& adjacency, vector<string>& names, vector<string>& targetPath, int pos, int node, vector<vector<int>>& dp) {
    if (pos == len) {
        return 0;
    }
    int &ret = dp[pos][node];
    if (ret != -1) {
        return dp[pos][node];
    }
    ret = numeric_limits<int>::max();
    for (auto next: adjacency[node]) {
        ret = min(ret, findMinEditDistance(len, adjacency, names, targetPath, pos + 1, next, dp));
    }
    ret += names[node] != targetPath[pos];
    return ret;
}

void findMinPath(int len, vector<vector<int>>& adjacency, vector<string>& names, vector<string>& targetPath, int pos, int node, vector<vector<int>>& dp, vector<int>& ans) {
    ans.push_back(node);
    if (pos == len - 1) {
        return;
    }
    int &ret = dp[pos][node];
    int cur = names[node] != targetPath[pos];
    for (auto next: adjacency[node]) {
        if (ret == cur + dp[pos + 1][next]) {
            findMinPath(len, adjacency, names, targetPath, pos + 1, next, dp, ans);
            break;
        }
    }
    return;
}

public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<vector<int>> adjacency(n, vector<int> ());
        for (auto& road: roads) {
            int a = road[0];
            int b = road[1];
            adjacency[a].push_back(b);
            adjacency[b].push_back(a);
        }        

        vector<vector<int>> dp(targetPath.size(), vector<int> (n, -1));
        int ans = numeric_limits<int>::max();
        int startIndex;
        for (int i = 0; i < n; i++) {
            int cur = findMinEditDistance(targetPath.size(), adjacency, names, targetPath, 0, i, dp);
            if (cur < ans) {
                ans = cur;
                startIndex = i;
            }
        }

        vector<int> path;
        findMinPath(targetPath.size(), adjacency, names, targetPath, 0, startIndex, dp, path);

        return path;
    }
};
