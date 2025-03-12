class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(2, vector<int> (n, 1));
        int cur = 0, next = 1;

        for (int i = 1; i < m; i++) {
            swap(cur, next);
            for (int j = 1; j < n; j++) {
                dp[cur][j] = dp[next][j] + dp[cur][j - 1];
            }
        }

        return dp[cur][n - 1];
    }
};
