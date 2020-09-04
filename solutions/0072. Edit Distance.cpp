////////////////////////////////////////////////////////////////////////////////////////////
Recursive DP
////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int solve(int pos1, int pos2, string& word1, string& word2,  vector<vector<int>>& dp) {
        if (pos1 == -1 || pos2 == -1) {
            return 1 + max(pos1, pos2);
        } else if (dp[pos1][pos2] != -1) {
            return dp[pos1][pos2];
        } else {
            int res = solve(pos1 - 1, pos2 - 1, word1, word2, dp);
            return dp[pos1][pos2] =
                word1[pos1] == word2[pos2] ?
                res :
                1 + min(res, min(solve(pos1 - 1, pos2, word1, word2, dp),
                                 solve(pos1, pos2 - 1, word1, word2, dp)));
        }
    }
    
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1, vector<int> (len2, -1));
        return solve(len1 - 1, len2 - 1, word1, word2, dp);
    }
};

////////////////////////////////////////////////////////////////////////////////////////////
Iterative DP
////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        
        vector<vector<int>> dp(n1 + 2, vector<int> (n2 + 2, numeric_limits<int>::max()));
        dp[0][0] = 0;
        for (int i = 1; i <= n1; i++) dp[i][0] = i;
        for (int j = 1; j <= n2; j++) dp[0][j] = j;
        
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                else dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
        }
        
        return dp[n1][n2];
    }
};
