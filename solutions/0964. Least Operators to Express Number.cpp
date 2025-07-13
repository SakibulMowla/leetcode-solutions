class Solution {
private:
    long long pow(long long base, long long expo) {
        if (expo == 0)
            return 1;
        if (expo == 1)
            return base;
        
        long long res = pow(base, expo / 2);
        return (expo % 2 == 1) ? res * res * base : res * res;
    }

    int findExponent(int x, int left) {
        int expo = 0;
        while (left >= x) {
            expo++;
            left /= x;
        }
        return expo;
    }

    int solve(int x, int left, unordered_map<long long, int>& dp) {
        if (left == 0)
            return 0;
        if (left == x)
            return 1;
        if (dp.contains(left))
            return dp[left];
        if (left < x)
            // either add or subtract from x towards the target
            return dp[left] = min(left * 2, (x - left) * 2 + 1);

        int expo = findExponent(x, left);
        long long low = pow(x, expo);
        long long high = pow(x, expo + 1);

        int ret = expo + solve(x, (int)(left - low), dp);
        // overshoot only when appropriate
        if (high - left < left)
            ret = min(ret, (expo + 1) + solve(x, (int)(high - left), dp));

        return dp[left] = ret;
    }

public:
    int leastOpsExpressTarget(int x, int target) {
        unordered_map<long long, int> dp;
        return solve(x, target, dp) - 1;
    }
};
