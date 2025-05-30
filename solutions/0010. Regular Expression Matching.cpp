class Solution {
public:
    bool solve(int sPos, int pPos, vector<vector<bool>>& visited, string& s, string& p) {
        if (sPos == -1) {
            while (pPos >= 0 && p[pPos] == '*') {
                pPos -= 2;
            }
        }
        if (sPos == -1 && pPos == -1) return true;
        if (sPos == -1 || pPos == -1) return false;
        if (visited[sPos][pPos]) return false;
        
        visited[sPos][pPos] = true;
        
        if (p[pPos] == '.') {
            return solve(sPos - 1, pPos - 1, visited, s, p);
        } else if (p[pPos] == '*') {
            bool ret = false;
            char prev = p[pPos - 1];
            if (prev == '.' || prev == s[sPos]) {
                ret = solve(sPos - 1, pPos, visited, s, p);
            }
            return ret || solve(sPos, pPos - 2, visited, s, p);
        } else {
            return s[sPos] == p[pPos] ? solve(sPos - 1, pPos - 1, visited, s, p) : false;
        }
    }
    
    bool isMatch(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        
        vector<vector<bool>> visited(sLen, vector<bool> (pLen, false));
        return solve(sLen - 1, pLen - 1, visited, s, p);
    }
};

// ------------------------------------------------------------------------

class Solution {
private:
    int solve(string&s, string& p, int sIndex, int pIndex, vector<vector<int>>& dp) {
        if (sIndex == s.size() && pIndex == p.size()) {
            return 1;
        }
        if (pIndex == p.size()) {
            return 0;
        }
        
        if (sIndex == s.size()) {
            while (pIndex + 1 < p.size() && p[pIndex + 1] == '*') {
                pIndex += 2;
            }
            return pIndex == p.size();
        }

        int& ret = dp[sIndex][pIndex];
        if (ret != -1) {
            return ret;
        }

        bool match = (s[sIndex] == p[pIndex] || p[pIndex] == '.');
        if (pIndex + 1 < p.size() && p[pIndex + 1] == '*') {
            ret = solve(s, p, sIndex, pIndex + 2, dp) ||
                  (match && solve(s, p, sIndex + 1, pIndex, dp));
        } else {
            ret = match && solve(s, p, sIndex + 1, pIndex + 1, dp);
        }

        return ret;
    }

public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        vector<vector<int>> dp(sLen, vector<int> (pLen, -1));

        return bool(solve(s, p, 0, 0, dp));
    }
};
