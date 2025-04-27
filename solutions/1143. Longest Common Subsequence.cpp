// Time - O(n * m)
// Memory - O(n * m)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                dp[i][j] = max((int)(text1[i - 1] == text2[j - 1]) + dp[i - 1][j - 1],
                              max(dp[i - 1][j], dp[i][j - 1]));
            }
        }

        return dp[len1][len2];
    }
};

// ---------------------------------------------------------------

// Time - O(n * m)
// Memory - O(m)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> dp(2, vector<int>(len2 + 1, 0));

        int prev = 1, cur = 0;

        for (int i = 1; i <= len1; i++) {
            swap(prev, cur);
            for (int j = 1; j <= len2; j++) {
                dp[cur][j] = max((int)(text1[i - 1] == text2[j - 1]) + dp[prev][j - 1],
                              max(dp[prev][j], dp[cur][j - 1]));
            }
        }

        return dp[cur][len2];
    }
};
