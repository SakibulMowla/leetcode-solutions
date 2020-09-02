class Solution {
public:
    vector<int> dp;
    
    Solution(): dp(46) {
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= 45; i++) {
            dp[i] += dp[i - 1] + dp[i - 2];
        }
    }
    
    int climbStairs(int n) {
        return dp[n];
    }
};
