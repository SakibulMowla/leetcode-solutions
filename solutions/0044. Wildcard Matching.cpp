class Solution {
private:
    int sLen, pLen;
    vector<vector<int>> dp;

    int solve(string& s, string& p, int sPos, int pPos) {
        if (sPos == sLen) {
            while (pPos < pLen && p[pPos] == '*') 
                pPos++;
            return pPos == pLen ? 1 : 0;
        }

        if (pPos == pLen)
            return 0;

        int ret = dp[sPos][pPos];
        if (ret != -1) {
            return ret;
        }

        bool isMatch = (s[sPos] == p[pPos]) ||
                       (p[pPos] == '?');
        if (p[pPos] == '*') {
            ret = max(solve(s, p, sPos, pPos + 1), solve(s, p, sPos + 1, pPos));
        } else if (isMatch) {
            ret = solve(s, p, sPos + 1, pPos + 1);
        }

        return dp[sPos][pPos] = ret;
    }

public:
    bool isMatch(string s, string p) {
        sLen = s.size(), pLen = p.size();
        dp = vector<vector<int>> (sLen, vector<int> (pLen, -1));

        return solve(s, p, 0, 0) == 1;
    }
};
