// Recursive

class Solution {
private:
    int solve(int n, vector<int>& dp) {
        if (n <= 0)
            return 1;

        int ret = dp[n];
        if (ret != -1)
            return ret;

        ret = 0;
        for (int i = 1; i <= n; i++) {
            ret += solve(i - 1, dp) * solve(n - i, dp);
        }

        return dp[n] = ret;
    }

public:
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

// ------------------------------------------------

// Bottom-up

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
