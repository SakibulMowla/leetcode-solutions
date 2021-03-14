class Solution {
public:    
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(2, vector<int> (cols + 1, 0));
        int ans = 0;
        
        for (int i = 1, now = 1, prev = 0; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[now][j] = 1 + min(dp[prev][j - 1],min(dp[prev][j], dp[now][j - 1]));
                    ans = max(ans, dp[now][j]);
                } else {
                    dp[now][j] = 0;
                }
            }
            swap(now, prev);
        }
        
        return ans * ans;
    }
};
