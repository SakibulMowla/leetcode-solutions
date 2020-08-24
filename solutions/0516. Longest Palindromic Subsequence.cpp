class Solution {
public:
    int solve(int startIndex, int endIndex, string& s, vector<vector<int>>& dp) {
        if (startIndex == endIndex) {
            return 1;
        } else if (startIndex > endIndex) {
            return 0;
        } else if (dp[startIndex][endIndex] != -1) {
            return dp[startIndex][endIndex];
        } else {
            return dp[startIndex][endIndex] = s[startIndex] == s[endIndex] ?
                2 + solve(startIndex + 1, endIndex - 1, s, dp) :
                max(solve(startIndex + 1, endIndex, s, dp), solve(startIndex, endIndex - 1, s, dp));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, n - 1, s, dp);
    }
};
