class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int coin: coins) {
            for (int i = coin; i <= amount; i++) {
                if (dp[i - coin] != numeric_limits<int>::max()) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        return dp[amount] == numeric_limits<int>::max() ? -1 : dp[amount];
    }
};
