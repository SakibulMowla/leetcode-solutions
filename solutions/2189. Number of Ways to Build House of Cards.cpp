class Solution {
private:
    int cardsNeeded(int n) {
        return n * 3 - 1;
    }

    int solve(int left, int lastRow, vector<vector<int>>& dp) {
        if (left == 0) {
            return 1;
        }

        int& ret = dp[left][lastRow];
        if (ret != -1) {
            return ret;
        }

        ret = 0;
        for (int i = 1; i < lastRow; i++) {
            if (left - cardsNeeded(i) >= 0) {
                ret += solve(left - cardsNeeded(i), i, dp);
            }
        }

        return ret;
    }

public:
    int houseOfCards(int n) {
        // left, last row
        vector<vector<int>> dp(n + 1, vector<int> (n + 2, -1));
        return solve(n, n + 1, dp);
    }
};
