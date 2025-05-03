// DP - Top Down
// Time - O(n)
// Space - O(n)

class Solution {
private:
    int maxProfitHelper(int index, int n, bool isBuy, vector<int>& prices, vector<vector<int>>& dp) {
        if (index >= n) {
            return 0;
        }

        if (dp[index][isBuy] != INT_MIN) {
            return dp[index][isBuy];
        }

        // skip this index
        int ret = maxProfitHelper(index + 1, n, isBuy, prices, dp);

        if (isBuy) {
            ret = max(ret, maxProfitHelper(index + 1, n, !isBuy, prices, dp) - prices[index]);
        } else {
            ret = max(ret, maxProfitHelper(index + 2, n, !isBuy, prices, dp) + prices[index]);
        }

        return dp[index][isBuy] = ret;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, INT_MIN));

        return maxProfitHelper(0, n, true, prices, dp);
    }
};

// ----------------------------------------------------------------

// DP - Bottom Up (Optimized)
// Time - O(n ^ 2)
// Space - O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, 0);

        // loop to sell
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            // loop to buy
            for (int j = 0; j < i; j++) {
                int profit = prices[i] - prices[j];
                dp[i] = max(dp[i], profit + (j >= 2 ? dp[j - 2] : 0));
            }
        }

        return dp[n - 1];
    }
};

// ----------------------------------------------------------------

// DP - Bottom Up (Optimized)
// Time - O(n)
// Space - O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 1; buy >= 0; buy--) {
                int prev = dp[i + 1][buy];
                if (buy) {
                    dp[i][buy] = max(prev, dp[i + 1][0] - prices[i]);
                } else {
                    dp[i][buy] = max(prev, i + 2 < n ? dp[i + 2][1] + prices[i] : prices[i]);
                }
            }
        }

        return dp[0][1];
    }
};
