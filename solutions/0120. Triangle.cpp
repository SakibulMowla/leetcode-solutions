class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(2, vector<int> (n, numeric_limits<int>::max()));
        
        dp[0][0] = triangle[0][0];
        int cur = 0;
        int prev = 1;

        for (int i = 1; i < n; i++) {
            swap(cur, prev);
            for (int j = 0; j <= i; j++) {
                dp[cur][j] = triangle[i][j] +
                    (j ? min(dp[prev][j - 1], dp[prev][j]) : dp[prev][j]);
            }
        }
        
        int ans = dp[cur][0];
        for (int i = 1; i < n; i++) {
            ans = min(ans, dp[cur][i]);
        }
        
        return ans;
    }
};
