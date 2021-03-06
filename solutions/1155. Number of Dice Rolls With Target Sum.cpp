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
