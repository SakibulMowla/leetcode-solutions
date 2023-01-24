// Recursive DP
// Time - O(N * K * T)
// Space - O(N * T)
class Solution {
public:
    const int mod = 1E9 + 7;

    int solve(int d, int f, int target, vector<vector<int>>& dp) {
        if (target < 0) {
            return 0;
        }
        if (d == 0) {
            return target == 0;
        }
        if (dp[d][target] != -1) {
            return dp[d][target];
        }
        int ret = 0;
        for (int i = 1; i <= f; i++) {
            ret = (ret + solve(d - 1, f, target - i, dp)) % mod;
        }
        return dp[d][target] = ret;
    }

    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d + 1, vector<int> (target + 1, -1));
        return solve(d, f, target, dp);
    }
};

// Iterative DP
// Time - O(N * K * T)
// Space - O(N * T)
class Solution {
private: 
    const int mod = 1E9 + 7;
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int> (target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int face = 1; face <= k; face++) {
                for (int sum = face; sum <= target; sum++) {
                    dp[i][sum] = dp[i][sum] + dp[i - 1][sum - face];
                    if (dp[i][sum] >= mod) {
                        dp[i][sum] -= mod;
                    }
                }
            }
        }

        return dp[n][target];
    }
};

// Iterative DP + Row swap
// Time - O(N * K * T)
// Space - O(T)
class Solution {
private: 
    const int mod = 1E9 + 7;
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(2, vector<int> (target + 1, 0));
        dp[0][0] = 1;
        int prevRow = 1, curRow = 0;

        for (int i = 1; i <= n; i++) {
            swap(curRow, prevRow);
            fill(dp[curRow].begin(), dp[curRow].end(), 0);
            for (int face = 1; face <= k; face++) {
                for (int sum = face; sum <= target; sum++) {
                    dp[curRow][sum] += dp[prevRow][sum - face];
                    if (dp[curRow][sum] >= mod) {
                        dp[curRow][sum] -= mod;
                    }
                }
            }
        }

        return dp[curRow][target];
    }
};
