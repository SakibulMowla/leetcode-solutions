class Solution {
private:
    using vi = vector<int>;
    using vii = vector<vi>;
    using viii = vector<vii>;
    
public:
    int longestLine(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        int ans = 0;
        viii dp(2, vii(cols, vi(4, 0)));
        
        int now = 0;
        int prev = 1;

        for (int i = 0; i < rows; i++) {
            swap(now, prev);
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    dp[now][j][0] = (j - 1 >= 0) ? dp[now][j - 1][0] + 1 : 1;
                    dp[now][j][1] = (i - 1 >= 0) ? dp[prev][j][1] + 1 : 1;
                    dp[now][j][2] = (i - 1 >= 0 && j - 1 >= 0) ? dp[prev][j - 1][2] + 1 : 1;
                    dp[now][j][3] = (i - 1 >= 0 && j + 1 < cols) ? dp[prev][j + 1][3] + 1 : 1;
                    ans = max(ans, max(max(dp[now][j][0], dp[now][j][1]), max(dp[now][j][2], dp[now][j][3])));
                } else {
                    dp[now][j][0] = dp[now][j][1] = dp[now][j][2] = dp[now][j][3] = 0;
                }
            }
        }

        return ans;
    }
};
