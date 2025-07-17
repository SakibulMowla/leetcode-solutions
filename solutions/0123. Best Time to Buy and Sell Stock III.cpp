class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefix(n, 0), suffix(n, 0);

        for (int i = 0, minVal = prices[0]; i < n; i++) {
            prefix[i] = max(0, prices[i] - minVal);
            if (i > 0)
                prefix[i] = max(prefix[i], prefix[i - 1]);
            minVal = min(minVal, prices[i]);
        }

        int ans = prefix[n - 1];
        for (int i = n - 1, maxVal = prices[n - 1]; i >= 0; i--) {
            suffix[i] = max(0, maxVal - prices[i]);
            if (i + 1 <= n - 1)
                suffix[i] = max(suffix[i], suffix[i + 1]);
            maxVal = max(maxVal, prices[i]);

            ans = max(ans, suffix[i] + (i - 1 >= 0 ? prefix[i - 1] : 0));
        }

        return ans;
    }
};
