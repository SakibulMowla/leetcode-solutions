class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        s = '0' + s;
        for (int i = 1; i <= n; i++) {
            if (s[i] >= '1' && s[i] <= '9') dp[i] += dp[i - 1];
            int twoDigit = ((s[i - 1] - '0') * 10 + s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};
