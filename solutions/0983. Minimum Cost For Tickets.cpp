class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 0);
        int n = days.size();
        int last = 0;
        for (int i = 0; i < n; i++) {
            for (int j = last + 1; j < days[i]; j++) {
                dp[j] = dp[last];
            }
            dp[days[i]] = costs[0] + dp[days[i] - 1];
            dp[days[i]] = min(dp[days[i]], costs[1] + (days[i] - 7 > 0 ? dp[days[i] - 7] : 0));
            dp[days[i]] = min(dp[days[i]], costs[2] + (days[i] - 30 > 0 ? dp[days[i] - 30] : 0));
            last = days[i];
        }
        return dp[days[n - 1]];
    }
};
