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
